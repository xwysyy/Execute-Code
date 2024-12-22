from ask import ask, models_list
from run import run, run_all
from init import problem_path, template_path, data_path
import os
if __name__ == '__main__':
    # Ask user to select a model
    problem_name = 'cf/1/0'
    path = problem_path + problem_name
    if not os.path.exists(path):
        os.makedirs(path)

    tem_model_list = [model for model in models_list if not os.path.exists(f'{path}/codes/{model}.h')]
        
    # ask(problem_name, tem_model_list)

    run_all(problem_name)