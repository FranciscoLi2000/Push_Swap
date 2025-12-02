# 📦 Push_swap: Efficient Stack Sorting Algorithm

> "Data Sorting as Logistics Optimization"
> An algorithmic project that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions.

# 📖 Overview | 项目概述

Push_swap 是 42 课程体系中的核心算法项目。任务非常直观：给定两个栈（Stack A 和 Stack B）和一组初始乱序整数，利用一组特定的指令（Push, Swap, Rotate），将 Stack A 中的数据按升序排列。

## 工程挑战：

不仅仅是排序，而是成本优化。
* 我们不计较 CPU 的比较时间，只计较输出的指令行数。
* 项目受到严格的内存管理限制（无泄漏）和错误处理要求（鲁棒性）。

## 切入点 (The Approach):

作为一名具有物流与供应链管理背景的开发者，我将此项目视为一个集装箱堆场调度问题 (Container Yard Optimization)。每一个数字不仅是数据，更是具有"运输成本"的货物。我采用了 Greedy Cost Algorithm (贪心成本算法)，通过预计算每一步的移动代价，寻找全局最优路径。

# 🚀 The Algorithm | 核心算法逻辑

本项目摒弃了传统的 QuickSort 或 Radix Sort，采用了针对双栈操作优化的 "Turk Algorithm" (Cost-based Greedy Sort)。
核心概念：Cheapest Move (最廉价移动)
每一轮操作前，程序会遍历栈 B 中的所有节点，计算将其移动到栈 A 正确位置所需的总步数 (Cost)。

## 算法流程 (Pipeline)

* 初始化 (Push to B):
	* 将 Stack A 中除了 3 个节点以外的所有节点推入 Stack B。
	* 优化策略： 在推入过程中，尝试将 B 维持在局部降序，或者将极值推到底部，为后续回归做铺垫。
* 微型排序 (Tiny Sort):
	* 对 Stack A 中剩余的 3 个节点进行硬编码排序（最多 2 步）。
* 回归排序 (Push back to A):
	* 核心循环： 只要 B 不为空：
		* 计算 B 中每个节点归位到 A 的成本。
	* 选择 Cost 最低 的节点。
* 双旋优化 (Simultaneous Rotation): 如果目标位置和当前位置都需要向上（或向下）旋转，使用 rr 或 rrr 指令合并操作，大幅降低成本。
	* 执行操作，将该节点推回 A (pa)。
* 最终调整 (Final Adjustment):
	* 此时 A 已有序，但最小元素可能不在栈顶。
	* 旋转 A 直到最小元素位于顶部。

# 🛠️ Installation & Usage | 安装与使用

1. 编译 (Compilation)
	项目包含一个标准的 Makefile。
	`git clone <repo_url> push_swap`
	`cd push_swap`
	`make`
	这将生成可执行文件 push_swap。

2. 运行 (Execution)
	`./push_swap 2 1 3 6 5 8`
	输出：生成的一系列排序指令（sa, pb, ra 等）。

3. 验证 (Verification)
	配合 checker 程序验证结果：
	`ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`
	如果输出 OK，则排序成功。

4. 性能测试 (Benchmark)
	使用 wc -l 统计指令行数：
	`ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l`

# 📂 Project Structure | 项目结构

本项目采用了高度模块化的架构设计，实现了逻辑层、驱动层与接口层的分离。
.
├── includes
│   └── push_swap.h       # API 契约：所有结构体与函数原型
├── libft                 # 基础工具库 (String, Memory, List utils)
├── srcs
│   ├── main.c            # 程序入口与调度器 (Dispatcher)
│   ├── algorithm         # [大脑] 核心排序逻辑
│   │   ├── sort_turk.c   # Turk 算法主循环
│   │   ├── algo_logic.c  # 成本计算与目标锁定 (Targeting)
│   │   └── algo_utils.c  # 双旋优化实现 (rr/rrr logic)
│   ├── commands          # [驱动] 底层指令集 implementation
│   │   ├── push.c
│   │   ├── swap.c
│   │   ├── rotate.c
│   │   └── rev_rotate.c
│   ├── parsing           # [安检] 输入验证系统
│   │   ├── check_input.c # 验证非数字、重复项、整数溢出
│   │   └── init_stack.c  # 参数解析与链表构建
│   └── utils             # [工具] 通用辅助函数
│       ├── stack_utils.c # 长度、极值查找、排序检查
│       └── error.c       # 内存清理与错误退出
└── Makefile              # 自动化构建脚本

# 🐛 Debugging Tips | 调试指南 (For Developer)

1. 内存泄漏检查 (Valgrind)
	由于使用了链表和 ft_split，必须确保所有 malloc 都有对应的 free。
	`valgrind --leak-check=full --show-leak-kinds=all ./push_swap 1 3 5 2`

2. 可视化 (Visualizer)
	推荐使用 Python 可视化脚本来观察算法行为：
	(此处未来可能放一个 visualizer 链接)

3. 常见陷阱
	* Input Parsing: 记得测试 "" (空字符串), " " (空格), "+" (仅符号)。
	* Integer Overflow: 2147483648 应该报错 Error。
	* Duplicates: 1 2 3 3 应该报错 Error。

# 📊 Performance Goals | 性能指标

基于 Turk 算法的预期表现：
| Stack Size | Target Instructions | Algorithm Complexity |
|------------|---------------------|----------------------|
| 3 Numbers  | ≤ 2                 | O(1)                 |
| 5 Numbers  | ≤ 12                | O(1)                 |
| 100 Numbers| < 700 (Avg: ~600)   | Approaching O(N) via Optimization |
| 500 Numbers| < 5500 (Avg: ~4500) | Efficient Greedy Heuristic |

# 👨‍💻 Author

[Li, Yufeng / Francisco]
* Role: 42 Barcelona Student
* Focus: Efficient Algorithms, Clean Code, System Architecture.
* Background: Logistics & Supply Chain Management, Spanish Filology, Communication Science, Hospitality Management

