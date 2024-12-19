from ask import ask, models_list
from run import run
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
        problem_level_path = f'{problem_path}/{id}/{level}'
        if not os.path.exists(problem_level_path):
            shutil.copytree(template_path, problem_level_path)
    
        if len(generator) == 0:
            raise Exception(f'Generator not found in problem {id} level {level}')
        if len(std) == 0:
            raise Exception(f'Std not found in problem {id} level {level}')
        
        with open(f'{problem_level_path}/generate/generator.cpp', 'w', encoding='utf-8') as f:
            f.write(generator)
        with open(f'{problem_level_path}/generate/std.cpp', 'w', encoding='utf-8') as f:
            f.write(std)

        desc = desc.replace('@data', str(data[level]))
        desc_zh = desc_zh.replace('@data', str(data[level]))
        desc = desc.replace('@time_limit', str(time_limit))
        desc_zh = desc_zh.replace('@time_limit', str(time_limit))
        desc = desc.replace('@memory_limit', str(memory_limit[level]))
        desc_zh = desc_zh.replace('@memory_limit', str(memory_limit[level]))
        with open(f'{problem_level_path}/desc/desc.txt', 'w', encoding='utf-8') as f:
            f.write(desc)
        with open(f'{problem_level_path}/desc/desc_zh.txt', 'w', encoding='utf-8') as f:
            f.write(desc_zh)

        test_data_file = []
        for item in data:
            test_data_file.append({"N": item})
        with open(f'{problem_level_path}/generate/test_data.json', 'w', encoding='utf-8') as f:
            json.dump(test_data_file, f, ensure_ascii=False, indent=4)

        os.system(f'bash {problem_level_path}/generate/generate.sh')

        with open(f'{problem_level_path}/problem.json', 'r', encoding='utf-8') as f:
            problem_json_file = json.load(f)
        problem_json_file['time_limit'] = int(time_limit)
        problem_json_file['memory_limit'] = int(memory_limit[level])
        for order in range(1, len(data)):
            tem = {
                "handle": f'{order}',
                "name": f'Test #{order}',
                "input": f'cases/{order}.in',
                "output": f'cases/{order}.out'
            }
            problem_json_file['test_cases'].append(tem)
        with open(f'{problem_level_path}/problem.json', 'w', encoding='utf-8') as f:
            json.dump(problem_json_file, f, ensure_ascii=False, indent=4)


def create_problem():
    """
    读取数据并使用并发处理每一行。
    """
    df = pd.read_csv(data_path + '/data.csv', encoding=encoding)

    with ThreadPoolExecutor() as executor:
        executor.map(process_row, df.to_dict(orient='records'))


create_problem()
