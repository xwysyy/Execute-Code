from ask import ask, models_list
from run import run, run_all
from init import problem_path, template_path, data_path
import os
import shutil
import pandas as pd
import chardet
import json
from concurrent.futures import ThreadPoolExecutor

# 检测文件编码
with open(data_path + '/data.csv', 'rb') as f:
    encoding = chardet.detect(f.read())['encoding']

def process_row(row):
    """
    处理单行数据的函数，负责完成每个问题的创建和生成。
    """
    id = row['id']
    desc = row['desc']
    desc_zh = row['desc_zh']
    data = list(map(int, row['data'].split()))
    time_limit = row['time_limit']
    memory_limit = list(map(int, row['memory_limit'].split()))
    std = row['std']
    generator = row['generator']

    # 设定单个数据范围测试点数目为2
    test_data_num = 2

    for level in range(len(memory_limit)):
        # 判断该题目配置内容是否修改或者是否新创建
        flag = False

        problem_level_path = f'{problem_path}/{id}/{level}'
        if not os.path.exists(problem_level_path):
            flag = True
            shutil.copytree(template_path, problem_level_path)
    
        if not generator:
            raise Exception(f'Generator not found in problem {id} level {level}')
        if not std:
            raise Exception(f'Std not found in problem {id} level {level}')
        
        def operate_file(file_path: str, cur_content: str):
            full_path = f'{problem_level_path}/{file_path}'
            nonlocal flag
            try:
                with open(full_path, 'r+', encoding='utf-8') as f:
                    pre_content = f.read()
                    if pre_content != cur_content:
                        flag = True
                        f.seek(0)
                        f.write(cur_content)
                        f.truncate()
            except FileNotFoundError:
                with open(full_path, 'w', encoding='utf-8') as f:
                    f.write(cur_content)
                flag = True 

        desc = desc.replace('@data', str(data[level]))
        desc_zh = desc_zh.replace('@data', str(data[level]))
        desc = desc.replace('@time_limit', str(time_limit))
        desc_zh = desc_zh.replace('@time_limit', str(time_limit))
        desc = desc.replace('@memory_limit', str(memory_limit[level]))
        desc_zh = desc_zh.replace('@memory_limit', str(memory_limit[level]))
 

        operate_file('generate/generator.cpp', generator)
        operate_file('generate/std.cpp', std)
        operate_file('desc/desc.txt', desc)
        with open(f'{problem_level_path}/desc/desc_zh.txt', 'w', encoding='utf-8') as f:
            f.write(desc_zh)

        def operate_json(file_path: str, new_content: dict):
            full_path = f'{problem_level_path}/{file_path}'
            nonlocal flag
            try:
                with open(full_path, 'r', encoding='utf-8') as f:
                    pre_content = json.load(f)
                if pre_content != new_content:
                    flag = True
                    with open(full_path, 'w', encoding='utf-8') as f:
                        json.dump(new_content, f, ensure_ascii=False, indent=4)
            except (FileNotFoundError, json.JSONDecodeError):
                with open(full_path, 'w', encoding='utf-8') as f:
                    json.dump(new_content, f, ensure_ascii=False, indent=4)
                flag = True

        test_data_file = [{"N": item} for item in data]
        operate_json('generate/test_data.json', test_data_file)

        with open(f'{problem_level_path}/problem.json', 'r', encoding='utf-8') as f:
            problem_json_file = json.load(f)
        problem_json_file['time_limit'] = int(time_limit)
        problem_json_file['memory_limit'] = max(int(memory_limit[level])+500,5000)
        problem_json_file['real_memory_limit'] = int(memory_limit[level])
        problem_json_file['test_cases']=[]
        for order in range(len(data) * 2):
            problem_json_file["test_cases"].append({
                "handle": f'{order}',
                "name": f'Test #{order}',
                "input": f'cases/{order}.in',
                "output": f'cases/{order}.out'
            })
        operate_json('problem.json', problem_json_file)

        tem_name = f'{id}/{level}'
        if flag is True:
            os.system(f'bash {problem_level_path}/generate/generate.sh')
            print(f'{tem_name} changed')
            ask(tem_name)
            run_all(tem_name)
        else:
            print(f'{tem_name} not changed')

def create_problem(op: bool = True):
    """
    读取数据并使用并发/非并发处理每一行。
    """
    df = pd.read_csv(data_path + '/data.csv', encoding=encoding)

    if op is True:
        with ThreadPoolExecutor() as executor:
            executor.map(process_row, df.to_dict(orient='records'))
    else:
        for _, row in df.iterrows():
            process_row(row)

if __name__ == '__main__':
    print(f'Enabled models: {models_list}')
    create_problem()

