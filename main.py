from ask import ask, models_list
from run import *
from init import problem_path, template_path
import os
import shutil

def create_problem(name: str):

    path = problem_path + '/' + name
    if os.path.exists(path):
        print('该题目已存在')
        return
    
    shutil.copytree(template_path, path)
    print(f'题目{name}创建成功')

    
"""
创建题目, name为题目名称 
    create_problem(name: str)
example: 
    create_problem('test')

大模型生成代码, name为题目名称
    ask(name: str)
example:
    ask('test')

测评大模型代码, name为题目名称, code为待测试代码
    run(name: str, code: str)
    run_all(name: str)
example:
    run('test', 'qwen-coder-plus')
    run_all('test')
"""

if __name__ == '__main__':
    print(f'Enabled models: {models_list}')
    run_all('test')