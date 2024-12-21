import os
import yaml
import concurrent.futures
from openai import OpenAI
from dotenv import load_dotenv
from init import model_path, problem_path, data_path

load_dotenv()
with open(model_path, 'r', encoding='utf-8') as file:
    models_config = yaml.load(file, Loader=yaml.FullLoader)
models_list = [
    model for model in list(models_config.keys()) 
    if models_config[model].get('enabled', False) 
]
with open(f'{data_path}/prompt.txt', 'r', encoding='utf-8') as f:
    prompt = f.read()
def get_code(question: str, model: str, api_key: str, base_url: str):
    """
    调用指定大模型api生成指定问题的代码, question为问题描述, model为大模型名称
    """
    api_key = os.getenv(api_key)
    if api_key is None:
        raise ValueError('API Key not found')
    client = OpenAI(api_key = api_key, base_url = base_url)
    chat_completion = client.chat.completions.create(
        messages = [
            {"role": "system", "content": prompt},
            {"role": "user","content": question}
        ],
        model = model,
    )
    
    code = chat_completion.choices[0].message.content
    code = '/*\n\n' + code + '\n\n*/'
    code = code.replace('```cpp', '*/\n')
    code = code.replace('```', '\n/*')
    return code

def ask(name: str, models_list: list = models_list):
    """
    调用所有启用的大模型api生成指定问题的代码, name为问题名称, models_list为大模型列表, 默认为启用的大模型列表, 可以指定模型
    """
    if not os.path.exists(problem_path):
        os.makedirs(problem_path)
    path = f'{problem_path}/{name}'
    if not os.path.exists(path):
        raise ValueError('Problem not found')
    if not os.path.exists(f'{path}/desc/desc.txt'):
        raise ValueError('Problem description not found')
    with open(f'{path}/desc/desc.txt', 'r', encoding='utf-8') as f:
        problem = f.read()
    path = f'{path}/codes'
    if not os.path.exists(path):
        os.makedirs(path)

    def save_code(model: str):
        enaled = models_config[model]['enabled']
        if not enaled:
            return
        api_key = models_config[model]['api_key']
        if api_key is None:
            raise ValueError('API Key not found')
        base_url = models_config[model]['base_url']
        cpp_code = get_code(problem, model, api_key, base_url)
        with open(f'{path}/{model}.cpp', 'w', encoding='utf-8') as f:
            for chunk in [cpp_code[i:i+1024] for i in range(0, len(cpp_code), 1024)]:
                f.write(chunk)

    with concurrent.futures.ThreadPoolExecutor() as executor:
        executor.map(save_code, models_list)

if __name__ == '__main__':
    print(f'Enabled models: {models_list}')