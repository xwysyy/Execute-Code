import subprocess
import os
from init import problem_path, parent_path

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
    res = subprocess.run(path, shell=True)
    print(res)

run('test', 'qwen-coder-plus')
