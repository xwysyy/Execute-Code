import subprocess
import concurrent.futures
import os
import json
import threading
from init import problem_path, parent_path

mp = {
    0: 'Accepted',
    1: 'Presentation Error',
    2: 'Time Limit Exceeded',
    3: 'Memory Limit Exceeded',
    4: 'Wrong Answer',
    5: 'Runtime Error',
    6: 'Output Limit Exceeded',
    7: 'Compile Error',
    8: 'System Error'
}

lock = threading.Lock()

def run(problem: str, code: str):
    """
    测评某道题目指定大模型代码, name为题目名称, code为待测试代码
    """
    path1 = f'{parent_path}/deer-executor'
    if not os.path.exists(path1):
        raise ValueError('Deer Executor not found')
    path2 = f'{problem_path}/{problem}/problem.json'
    if not os.path.exists(path2):
        raise ValueError('Problem not found')
    path3 = f'{problem_path}/{problem}/codes/{code}.cpp'
    if not os.path.exists(path3):
        raise ValueError('Code not found')
    path = f'{path1} run {path2} {path3}'
    path_with_detail = f'{path1} run --detail {path2} {path3}'

    res = subprocess.run(path_with_detail, shell=True, capture_output=True)
    res = json.loads(res.stdout)

    with open(f'{problem_path}/{problem}/problem.json', 'r') as f:
        real_memory_limit = json.load(f)['real_memory_limit']
    
    res = res['data']['test_cases']
    
    res_data = []
    for item in res:
        handle = item['handle']
        result = mp[item['judge_result']]
        memory_used = max(0, (int)(item['memory_used']) - 500)
        if memory_used > (int)(real_memory_limit):
            if result == 'Accepted':
                result = 'Memory Limit Exceeded'
            elif result == 'Time Limit Exceeded':
                result = 'Time Limit Exceeded / Memory Limit Exceeded'
        time_used = item['time_used']
        res_data.append({
            'handle': handle,
            'result': result,
            'time_used': time_used,
            'memory_used': memory_used
        })
    
    with lock:
        result_file = f'{problem_path}/{problem}/result.json'
        if os.path.getsize(result_file) == 0:
            file_data = {}
        else:
            try:
                with open(result_file, 'r') as f:
                    file_data = json.load(f)
            except json.decoder.JSONDecodeError:
                file_data = {}

        file_data[code] = res_data

        with open(result_file, 'w') as f:
            json.dump(file_data, f, indent=4)

def run_all(problem: str, op: bool = True, code_list: list = None):
    """
    测评某道题目所有大模型代码, name为题目名称, op表示是否多线程
    """
    path = f'{problem_path}/{problem}/codes'
    if not os.path.exists(path):
        raise ValueError('Codes not found')
    if code_list is None:
        code_list = os.listdir(path)
        code_list = [code[:-4] for code in code_list]

    if op == True:
        with concurrent.futures.ThreadPoolExecutor() as executor:
            executor.map(run, [problem] * len(code_list), code_list)
    else:
        for code in code_list:
            run(problem, code)