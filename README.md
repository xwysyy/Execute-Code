# 准备

  * 需要安装jq，`sudo apt-get install jq`。
  * 未启用安全沙箱测试，需要配置python和cpp的编译环境，也可自行构建docker镜像。
  
# 使用

* 在`init/modules.yaml`中配置需要的大模型
* 在`.env`中配置api_key
* 请参照模版配置`data/data.csv`内容
* 在`data/prompt.txt`中配置大模型生成代码的prompt。
* 在`main.py`中，读取`data/data.csv`中的题目，并调用api生成代码，进行评测。
* 需要提供`data/test_cases.zip`文件，用于读取测试用例。
* 假设题目名称为`test`，并进入到`data/problems/test`目录下。
  * `problem.json`是题目测试的基本信息。
  * `result.json`是测试结果。
  * `cases`是测试用例。
  * `code`是大模型生成的代码。
  * `desc`是题目描述。

# 可能会出现的问题：

* 返回的代码部分缺少换行符，导致无法编译。
* bash脚本如果执行失败，可能是因为设置的是crlf换行符，需要转换为lf。
  > 确保文件的换行符是lf
  > ```shell
  > echo 'export FILEFORMAT=unix' >> ~/.bashrc
  > source ~/.bashrc
  > ```

# todo

* 对于同一题目同一接口多次询问返回的代码进行整理