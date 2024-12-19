# 准备

* 需要安装jq，`sudo apt-get install jq`。
* 由于未启用黑盒测试，需要在本地linux配置g++和python3环境，也可自行构建docker镜像。


# 使用

* 请参照`data/code/test`的内容，存放待测试的代码。
* 请参照`data/problem/test`的内容，构建自己的测试用例，注意保持`codes`和`problems`中的题目名称一致。
    * 假设此时已进入到`data/problem/test`目录下。
    * 需要在`problem.json`中配置测试用例数量和时空限制。
    * `generate/std.cpp`为标程。将按照std.cpp的输出结果生成测试用例。
    * 对于每个测试点的数据大小限制，请在`generate/test_data.json`中配置。
    * 请使用`generate/generate.cpp`完成测试数据的具体生成逻辑。
    * 最后，运行`generate/generate.sh`生成测试用例。
    * 生成的测试用例将存放在`cases`文件夹中。
* 在`exec/run.py`中指定题目名称和测试的代码名称进行测试。

# 调用api生成代码

# 使用
1. 在`init/modules.yaml`中配置需要的大模型
2. 在`.env`中配置api_key
3. 运行ask.py文件，输入问题，在code目录下生成问题的代码文件

# 可能会出现的问题：
1. 返回代码中并没有markdown语法的代码块标识符，导致全部被注释掉
2. 可能存在多个代码块被提取出来

# todo
1. 批量化导入题目
2. 规范化返回的代码
3. 对于同一题目同一接口多次询问返回的代码进行整理
