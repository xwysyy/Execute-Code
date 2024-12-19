import subprocess
import os
import json
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

def run(problem: str, code: str):

    path1 = parent_path + '/deer-executor'
    if not os.path.exists(path1):
        raise ValueError('Deer Executor not found')
    path2 = problem_path + '/' + problem + '/problem.json'
    if not os.path.exists(path2):
        raise ValueError('Problem not found')
    path3 = problem_path + '/' + problem + '/codes/' + code + '.cpp'
    if not os.path.exists(path3):
        raise ValueError('Code not found')
    path = path1 + ' run ' + path2 + ' ' + path3 
    path_with_detail = path1 + ' run  --detail ' + path2 + ' ' + path3 

    res = subprocess.run(path, shell=True, capture_output=True)
    res = json.loads(res.stdout)
    result = mp[res['data']['judge_result']]
    time_used = res['data']['time_used']
    memory_used = res['data']['memory_used']

    res_data = {
        'result': result,
		'time_used': time_used,
		'memory_used': memory_used
	}

    result_file = problem_path + '/' + problem + '/result.json'
    if os.path.getsize(result_file) == 0:
        file_data = {}
    else:
        try:
            with open(result_file, 'r') as f:
                file_data = json.load(f)
        except json.decoder.JSONDecodeError:
            file_data = {}
    
    file_data[code] = [res_data]

    with open(result_file, 'w') as f:
        json.dump(file_data, f, indent=4)   


run('test', 'qwen-coder-plus')
