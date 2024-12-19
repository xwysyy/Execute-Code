# 调用api生成代码

## 使用

* 在`init/modules.yaml`中配置需要的大模型
* 在`.env`中配置api_key
* 在`main.py`中创建新题目或者调用`ask()`函数获取大模型生成的代码
  > 现在需要自行配置题面
* 假设题目名称为`test`，则生成的代码将存放在`data/problem/test/codes`中

## 可能会出现的问题：

* 返回代码中并没有markdown语法的代码块标识符，导致全部被注释掉
* 可能存在多个代码块被提取出来

## todo

* 批量化导入题目
* 规范化返回的代码
* 对于同一题目同一接口多次询问返回的代码进行整理
   
# 测评代码

## 准备

* 需要安装jq，`sudo apt-get install jq`。
* 由于未启用黑盒测试，需要在本地linux配置g++和python3环境，也可自行构建docker镜像。


## 使用

* 请参照题目模版`init/template`的内容，构建测试体系。
* 假设生成的题目目录为`data/problem/test`，此时已经进入到该目录下。
    * 需要在`problem.json`中配置测试用例数量和时空限制。
      > 请注意，空间不要开得太大，在并发测试时可能会导致内存不足。
    * `generate/std.cpp`为标程。将按照std.cpp的输出结果生成测试用例。
    * 对于每个测试点的数据大小限制，请在`generate/test_data.json`中配置。
    * 请使用`generate/generate.cpp`完成测试数据的具体生成逻辑。
    * 最后，运行`generate/generate.sh`生成测试用例。
    * 生成的测试用例将存放在`cases`文件夹中。
* 在`mian.py`中指定题目名称和测试的代码名称进行测试，测试结果与时空消耗将存放在`data/problem/test/result.json`中。

