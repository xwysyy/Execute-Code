# 准备

  * 需要安装jq，`sudo apt-get install jq`。
  * 未启用安全沙箱测试，可自行构建docker镜像。
  
# 使用

* 在`init/modules.yaml`中配置需要的大模型
* 在`.env`中配置api_key
* 请参照模版配置`data/data.csv`内容
* 在`data/prompt.txt`中配置大模型生成代码的prompt。
* 在`main.py`中，读取`data/data.csv`中的题目，并调用api生成代码，进行评测。
* 假设题目名称为`test`，并进入到`data/problems/test`目录下。
  * `problem.json`是题目测试的基本信息。
  * `result.json`是测试结果。
  * `cases`是测试用例。
  * `code`是大模型生成的代码。
  * `desc`是题目描述。
  * `generate`用于生成测试用例，其中包括std.cpp和generate.cpp。

# 可能会出现的问题：

* 返回代码中并没有markdown语法的代码块标识符，导致全部被注释掉
* 可能存在多个代码块被提取出来

# todo

* 对于同一题目同一接口多次询问返回的代码进行整理