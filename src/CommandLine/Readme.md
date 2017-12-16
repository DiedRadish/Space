# CommandLine

这是一个用于处理命令行参数的库（仅针对Space项目）。

## 实现

### 结构

* CommandLine
  - <Unit[]>
    - [Argv[]]
      * <Name>
      * [Description]
      * [DefaultValue]
      * <:hasValue>
      * <:allowRepeat>
      * <:allowEmpty>
    - <Callback>
    - <Name>
    - [Description]
  - [Description]
  - <:hasHelp>
* Info
  * <InfoCode>
    * Success=1
    * ​
  * <Message>