import os
import shutil
import pandas as pd
import json
import chardet

def add_problem_folder(id: int):
    """
    添加指定题目文件夹, 后面的题目文件夹会自动向后移
    """
    max_id = 0
    for i in range(200, 0, -1):
        if os.path.exists(f'cf{i}'):
            max_id = i
            break
    for i in range(max_id, id - 1, -1):
        old_path = 'cf' + str(i)
        new_path = 'cf' + str(i + 1)
        shutil.move(old_path, new_path)
    shutil.copytree(f'cf1', f'cf{id}')

def load_csv(csv_path: str='data.csv'):
    """
    从 CSV 文件读取数据并填充到对应文件夹
    """
    with open(csv_path, 'rb') as f:
        encoding = chardet.detect(f.read())['encoding']
    df = pd.read_csv('data.csv', encoding=encoding)
    for _, row in df.iterrows():
        id = row['id']
        desc = row['desc']
        desc_zh = row['desc_zh']
        tem_data = row['data']
        data = list(map(int, tem_data.split()))
        time_limit = int(row['time_limit'])
        memory_limit = list(map(int, row['memory_limit'].split()))
        std = row['std']
        test_cpp = row['test']
        std = f'#ifndef STD_H\n#define STD_H\n#include <bits/stdc++.h>\nusing namespace std;\n\n{std}\n\n#endif'
        cate = row['cate']
        difficulty = row['difficulty']
        path=f'{id}'
        
        def operate_file(file_path: str, cur_content: str):
            with open(file_path, 'r+', encoding='utf-8') as f:
                f.seek(0)
                f.write(cur_content)
                f.truncate()
        
        operate_file(f'{path}/desc/desc.md', desc)
        operate_file(f'{path}/desc/desc_zh.md', desc_zh)
        operate_file(f'{path}/generate/std.h', std)
        operate_file(f'{path}/generate/test.cpp', test_cpp)
        with open(f'{path}/problem.json', 'w') as f:
            json.dump({
                'time_limit': time_limit,
                'memory_limit': memory_limit,
                'cate': cate,
                'difficulty': difficulty
            }, f, indent=4)
        with open(f'{path}/generate/test_data.json', 'w') as f:
            json.dump([{'N': N} for N in data], f, indent=4)
        
def store_csv(output_csv_path: str):
    """
    生成题目配置CSV文件
    """
    data_list = []
    prefix = ['cf', 'other']
    for pre in prefix:
        for i in range(1, 200):
            path = f'{pre}{i}'
            if not os.path.exists(path):
                break
            try:
                with open(f'{path}/desc/desc.md', 'r', encoding='utf-8') as f:
                    desc = f.read()
                with open(f'{path}/desc/desc_zh.md', 'r', encoding='utf-8') as f:
                    desc_zh = f.read()
                
                with open(f'{path}/generate/std.h', 'r', encoding='utf-8') as f:
                    std = f.read()
                
                std = 'class Solution' + std.split('class Solution')[1]
                std = std.split('#endif')[0]
                
                with open(f'{path}/generate/test.cpp', 'r', encoding='utf-8') as f:
                    test_cpp = f.read()
                
                with open(f'{path}/generate/test_data.json', 'r', encoding='utf-8') as f:
                    test_data = json.load(f)
                    data = ' '.join([str(d['N']) for d in test_data])
                with open(f'{path}/problem.json', 'r', encoding='utf-8') as f:
                    problem_data = json.load(f)
                    time_limit = problem_data['time_limit']
                    memory_limit = ' '.join(map(str, problem_data['memory_limit']))
                    cate = problem_data['cate']
                    difficulty = problem_data['difficulty']
                
                data_list.append({
                    'id': path,
                    'desc': desc,
                    'desc_zh': desc_zh,
                    'data': data,
                    'time_limit': time_limit,
                    'memory_limit': memory_limit,
                    'std': std,
                    'test': test_cpp,
                    'cate': cate,
                    'difficulty': difficulty
                })
            
            except Exception as e:
                print(f"Error processing {path}: {e}")
    
    df = pd.DataFrame(data_list)
    df.to_csv(output_csv_path, index=False, encoding='utf-8')
    print(f"Data successfully written to {output_csv_path}")

def load_cases(input_path: str):
    """
    从测试数据文件压缩包读取数据并填充到对应文件夹
    """
    shutil.unpack_archive(input_path, 'test_cases')
    prefix = ['cf', 'other']
    for pre in prefix:
        for i in range(1, 200):
            path = f'{pre}{i}'
            if not os.path.exists(path):
                break
            try:
                shutil.rmtree(f'{path}/cases')
                shutil.copytree(f'test_cases/{path}', f'{path}/cases')
            except Exception as e:
                print(f"Error processing {path}: {e}")
    
    shutil.rmtree('test_cases')
    print(f"Test cases successfully loaded from {input_path}")

def store_cases(output_path: str):
    """
    生成测试数据文件压缩包
    """
    prefix = ['cf', 'other']
    for pre in prefix:
        for i in range(1, 200):
            path = f'{pre}{i}'
            if not os.path.exists(path):
                break
            try:
                shutil.copytree(f'{path}/cases', f'{output_path}/{path}')
            except Exception as e:
                print(f"Error processing {path}: {e}")

    shutil.make_archive(output_path, 'zip', output_path)
    shutil.rmtree(output_path)
    print(f"Test cases successfully written to {output_path}.zip")
    

if __name__ == '__main__':
    # add_problem_folder(1)
    # load_csv('data.csv')
    store_csv('data.csv')
    # store_cases('test_cases')
    pass