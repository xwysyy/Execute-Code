import subprocess
import concurrent.futures
import os
import json
import threading
from init import problem_path

lock = threading.Lock()

def run(problem: str, code: str):
    """
    测评某道题目指定大模型代码, name为题目名称, code为待测试代码
    """
    path = f'{problem_path}/{problem}'
    if not os.path.exists(f'{path}/codes/{code}.h'):
        raise ValueError('Code or Problem not found')
    
    with open(f'{path}/problem.json', 'r') as f:
        tem_problem_json = json.load(f)
        time_limit = (int)(tem_problem_json['time_limit'])
        memory_limit = (int)(tem_problem_json['memory_limit'])
        test_case_num = (int)(tem_problem_json['test_case_num'])
    
    path_generate = f'{path}/generate'
    os.system(f'cp {path}/codes/{code}.h {path_generate}/test_{code}.h')
    os.system(f'cp {path_generate}/test.cpp {path_generate}/test_{code}.cpp')
    os.system(f'sed -i "s/#include \\"std.h\\"/#include \\"test_{code}.h\\"/g" {path_generate}/test_{code}.cpp')
    sign = os.system(f'g++ {path_generate}/test_{code}.cpp -o {path_generate}/test_{code}')
    res_data = []
    if sign != 0:
        for i in range(test_case_num):
            res_data.append({
                'case': f'{len(res_data)+i}',
                'result': 'Compile Error',
                'time_used': 0,
                'memory_used': 0
            })
    else:
        for i in range(test_case_num):
            shell = f'{path_generate}/test_{code} {i} < {path}/cases/{i}.in > {path_generate}/test_{code}{i}.out'
            shell_res = subprocess.run(shell, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            stderr = shell_res.stderr
            if "CPU time limit exceeded" in stderr:
                res_data.append({
                    'case': f'{i}',
                    'result': 'Time Limit Exceeded',
                    'time_used': 2000,
                    'memory_used': 0
                })
                continue
            shell = f'diff {path_generate}/test_{code}{i}.out {path}/cases/{i}.out > /dev/null 2>&1'
            sign = os.system(shell)
            if sign != 0:
                res_data.append({
                    'case': f'{i}',
                    'result': 'Wrong Answer',
                    'time_used': 0,
                    'memory_used': 0
                })
            else:
                with open(f'{path_generate}/test_{code}_result{i}.txt', 'r') as f:
                    time_before = (int)(f.readline())
                    memory_before = (int)(f.readline())
                    time_after = (int)(f.readline())
                    memory_after = (int)(f.readline())
                    time_used = time_after - time_before
                    memory_used = memory_after - memory_before
                tem_result = 'Accepted'
                if time_used > time_limit:
                    tem_result = 'Time Limit Exceeded'
                if memory_used > memory_limit:
                    if tem_result == 'Accepted':
                        tem_result = 'Memory Limit Exceeded'
                    else:
                        tem_result = 'Time Limit Exceeded / Memory Limit Exceeded'
                res_data.append({
                    'case': f'{i}',
                    'result': tem_result,
                    'time_used': time_used,
                    'memory_used': memory_used
                })
    os.system(f'rm -f {path_generate}/test_{code}*')

    with lock:
        result_file = f'{path}/result.json'
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
        code_list = [code[:-2] for code in code_list]

    if op == True:
        with concurrent.futures.ThreadPoolExecutor() as executor:
            executor.map(run, [problem] * len(code_list), code_list)
    else:
        for code in code_list:
            run(problem, code)

if __name__ == '__main__':
    run_all('1/1')
    # run_all('1/2')