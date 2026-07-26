# 数据结构 C 语言实现

本仓库存放大一暑假期间学习《数据结构》时手写的核心代码。  
目前已从“单文件验证”升级为“多文件工程结构”，并开始引入边界测试与 Git 分支管理。

---

## 工程结构

```text
.
├── sqlist.h            # 顺序表头文件（结构体定义、函数声明、头文件卫士）
├── sqlist.c            # 顺序表函数实现（增删改查、边界判断）
├── sqmain.c            # 顺序表测试入口
├── linklist.h          # 单链表头文件
├── linklist.c          # 单链表函数实现
├── linklistmain.c      # 单链表测试入口
├── doulinklist.h       # 双向链表头文件
├── doulinklist.c       # 双向链表函数实现
├── doulinklistmain.c   # 双向链表测试入口
└── README.md           # 本文件
```


## 编译与运行（多文件工程）

> 注意：本项目已不再使用 F5 一键运行，请手动执行以下命令。

```bash
# 编译顺序表测试程序
gcc sqlist.c sqmain.c -o build/test_sqlist

# 编译单链表测试程序
gcc linklist.c linklistmain.c -o build/test_linklist

# 编译双向链表测试程序
gcc doulinklist.c doulinklistmain.c -o build/test_doulinklist

# 运行测试
.\build\test_sqlist.exe
.\build\test_linklist.exe
.\build\test_doulinklist.exe
```

## 当前学习进度

| 数据结构 | 状态 | 备注 |
| --- | --- | --- |
| 顺序表（SqList） | 已完成 | 已拆分为 .h + .c + main.c，已加入边界防御 |
| 单链表（LinkList） | 已完成 | 已拆分为 .h + .c + main.c 多文件结构 |
| 双向链表（DouLinkList） | 待完成 | 带头结点的双向链表，支持增删改查 |
| 栈与队列 | 待学习 | — |

## 测试覆盖说明

各数据结构的测试入口均包含正常功能测试与边界异常测试：

### 顺序表（sqmain.c）

```text
向已满的顺序表插入元素 → 预期返回错误码
在非法位置（-1 或超出长度）操作 → 预期拒绝执行
对空表执行删除或取值操作 → 预期返回错误码
```

### 单链表（linklistmain.c）

```text
在空链表头插/尾插 → 正常插入
在中间位置插入/删除 → 正常操作
按值查找/按位置查找 → 返回正确结点
删除不存在的元素 → 预期返回错误码
```

### 双向链表（doulinklistmain.c）

```text
在空链表头插/尾插 → 正常插入
按位置插入/删除 → 正常操作
遍历打印 → 验证前后链接正确
在非法位置操作 → 预期拒绝执行
```

## 开发环境

- 编译器：MinGW (gcc)
- 编辑工具：Visual Studio Code
- 版本管理：Git + GitHub
- 编译方式：手动终端命令（不再依赖 IDE 一键运行）

## 维护日志

| 日期 | 变更说明 |
| --- | --- |
| 2026.07.26 | 更新 README 工程结构、编译命令与学习进度 |
| 2025.07.14 | 顺序表重构为多文件工程，增加头文件卫士与边界测试 |
| 2025.07.13 | 初始化仓库，上传单文件版本 |

## 备注

本仓库主要用于个人学习记录与工程能力训练，欢迎交流指正。

> 本仓库所有代码均在 AI 工具辅助下完成，使用的 AI 工具为 **GitHub Copilot**，并配置了 **DeepSeek V4 API** 作为底层模型。