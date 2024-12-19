from ask import *
from run import *
from init import problem_path, template_path
import os
import shutil

def create_problem(name: str):

    path = problem_path + '/' + name
    if os.path.exists(path):
        print('该题目已存在')
        return
    
    os.mkdir(path)
    shutil.copytree(template_path, path)
    print(f'题目{name}创建成功')

"""
大模型生成代码, name为题目名称
ask(name: str)

测评大模型代码, name为题目名称, code为待测试代码
run(name: str, code: str)
"""