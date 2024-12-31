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

def process_row(row: dict):
    """
    处理单行数据的函数，负责完成每个问题的创建和生成, row为字典类型
    """
    if not os.path.exists(problem_path):
        os.makedirs(problem_path)
    
    id = row['id']
    desc = row['desc']
    desc_zh = row['desc_zh']
    data = list(map(int, row['data'].split()))
    time_limit = int(row['time_limit'])
    memory_limit = list(map(int, row['memory_limit'].split()))
    std = row['std']
    test_cpp = row['test']
    cate = row['cate']
    difficulty = row['difficulty']
    if not all([desc, desc_zh, data, time_limit, memory_limit, std, test_cpp, cate, difficulty]):
        raise Exception(f'Problem {id} not complete')
    std = f'#ifndef STD_H\n#define STD_H\n#include <bits/stdc++.h>\nusing namespace std;\n\n{std}\n\n#endif'

    for level in range(len(memory_limit)):
        # 判断该题目配置内容是否修改或者是否新创建
        flag = False
        # 判断测试数据是否修改
        flag1 = False

        problem_level_path = f'{problem_path}/{id}/{level}'
        if not os.path.exists(problem_level_path):
            flag = True
            shutil.copytree(template_path, problem_level_path)
    
        if not std:
            raise Exception(f'Std not found in problem {id} level {level}')
        
        def operate_file(file_path: str, cur_content: str):
            full_path = f'{problem_level_path}/{file_path}'
            nonlocal flag
            try:
                with open(full_path, 'r+', encoding='utf-8') as f:
                    pre_content = f.read()
                    if pre_content != cur_content:
                        f.seek(0)
                        f.write(cur_content)
                        f.truncate()
                        if file_path != 'desc/desc.txt':
                            nonlocal flag1
                            flag1 = True
                        else:
                            flag = True
            except FileNotFoundError:
                with open(full_path, 'w', encoding='utf-8') as f:
                    f.write(cur_content)
                flag = True 
                
        new_desc = desc
        new_desc_zh = desc_zh
        new_desc = new_desc.replace('@data', str(data[len(memory_limit)-1]))
        new_desc_zh = new_desc_zh.replace('@data', str(data[len(memory_limit)-1]))
        new_desc = new_desc.replace('@time_limit', str(time_limit))
        new_desc_zh = new_desc_zh.replace('@time_limit', str(time_limit))
        new_desc = new_desc.replace('@memory_limit', str(memory_limit[level]))
        new_desc_zh = new_desc_zh.replace('@memory_limit', str(memory_limit[level]))

        new_std = std
        if f'solve{level}' in new_std:
            pre_std = new_std.split(f'solve')[0]
            suf_std = new_std.split(f'solve{level}')[1]
            if 'solve' in suf_std:
                suf_std = suf_std.split('solve')[0]
                pos = suf_std.rfind('}')
                suf_std = suf_std[:pos]
                new_std = pre_std + 'solve' + suf_std + '}\n};\n\n#endif'
            else:
                new_std = pre_std + 'solve' + suf_std

        operate_file('codes/std.h', new_std)
        operate_file('exec/test.cpp', test_cpp)
        operate_file('desc/desc.txt', new_desc)
        with open(f'{problem_level_path}/desc/desc_zh.txt', 'w', encoding='utf-8') as f:
            f.write(new_desc_zh)

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
        operate_json('exec/test_data.json', test_data_file)

        with open(f'{problem_level_path}/problem.json', 'r', encoding='utf-8') as f:
            problem_json_file = json.load(f)
        problem_json_file['time_limit'] = int(time_limit)
        problem_json_file['memory_limit'] = int(memory_limit[level])
        problem_json_file['cate'] = cate
        problem_json_file['difficulty'] = difficulty
        operate_json('problem.json', problem_json_file)

        test_case_path = f'{data_path}/test_cases/{id}'
        if not os.path.exists(test_case_path):
            raise Exception(f'Test cases for problem {id} not found')
        def compare_dir(dir1: str, dir2: str):
            nonlocal flag1
            if len(os.listdir(dir1)) != len(os.listdir(dir2)):
                flag1 = True
                return
            for file in os.listdir(dir1):
                file1 = f'{dir1}/{file}'
                file2 = f'{dir2}/{file}'
                try:
                    with open(file1, 'rb') as f1, open(file2, 'rb') as f2:
                        if f1.read() != f2.read():
                            flag1 = True
                            return
                except FileNotFoundError:
                    flag1 = True
                    return
        compare_dir(test_case_path, f'{problem_level_path}/cases')

        tem_name = f'{id}/{level}'
        if flag is True:
            print(f'{tem_name} changed')
            shutil.rmtree(f'{problem_level_path}/cases')
            shutil.copytree(test_case_path, f'{problem_level_path}/cases')
            ask(tem_name)
            run_all(tem_name)
        elif flag1 is True:
            print(f'{tem_name} test changed')
            shutil.rmtree(f'{problem_level_path}/cases')
            shutil.copytree(test_case_path, f'{problem_level_path}/cases')
            run_all(tem_name)
        else:
            tem_model_list = [model for model in models_list if not os.path.exists(f'{problem_level_path}/codes/{model}.h')]                    
            if tem_model_list:
                print(f'{tem_name} models changed')
                ask(tem_name, tem_model_list)
                run_all(tem_name, code_list=tem_model_list)
            else:
                print(f'{tem_name} not changed')
                
def create_problem(name: str = None, op: bool = True):
    """
    读取数据并使用并发/非并发处理每一行, name为是否指定题目名字, op为是否并发处理
    """
    if not os.path.exists(data_path + 'test_cases'):
        if not os.path.exists(data_path + '/test_cases.zip'):
            raise Exception('Test cases not found')
        shutil.unpack_archive(data_path + '/test_cases.zip', data_path + '/test_cases')
    df = pd.read_csv(f'{data_path}/data.csv', encoding=encoding)

    if name:
        df = df[df['id'] == name]
        if df.empty:
            raise Exception(f'Problem {name} not found')
        process_row(df.to_dict(orient='records')[0])
        return

    if op is True:
        with ThreadPoolExecutor(max_workers=2) as executor:
            executor.map(process_row, df.to_dict(orient='records'))
    else:
        for _, row in df.iterrows():
            process_row(row)

    shutil.rmtree(data_path + '/test_cases')

if __name__ == '__main__':
    print(f'Enabled models: {models_list}')
    create_problem()

