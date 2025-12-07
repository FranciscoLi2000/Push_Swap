# 📚 Push_Swap 项目理论与实现 (INTP)

本项目旨在通过最少的指令集对栈 A ordenar una secuencia aleatoria de enteros. La implementación sigue un diseño modular riguroso, el manejo de errores (mandatory part) y utiliza un algoritmo Greedy con análisis de costos para la optimización.

## I. ⚙️ 架构概览 (Architecture Overview)
### A. Entrada y Validación

确保输入有效 (数字，无重复，无溢出) 并构建循环双向链表。

stack_init, ft_atol, check_input, check_duplicates, check_overflow, handle_input_and_init

### B. Operaciones Mecánicas

实现 11 个原子操作 (sa, ra, pa, etc.)。

swap, push, rotate, reverse_rotate (及其 wrappers ss, rr, rrr)

### C. 预处理 (Pre-sorting)

将实际值转换为排名索引 (1 到 N) 以简化算法。

normalize_stack

### D. 排序算法

实现高效的排序策略 (Greedy/Radix)。

sort_three, sort_stacks, move_a_to_b

## II. 🧠 核心算法: Greedy 策略

Para pilas grandes (N > 5), el proyecto utiliza un algoritmo Greedy con análisis de costos, minimizando la suma total de rotaciones para cada elemento.

### 1. 初始阶段 (Initial Phase)

Normalization (normalize_stack): 将所有值替换为其排名 (1 = 最小，N = 最大)。

Move A to B (move_a_to_b): 将 A 中除了 3 个最大元素之外的所有数字移动到 B。

Sort 3 (sort_three): 使用 3 条指令的最小指令集对 A 中剩下的 3 个元素进行排序。

### 2. 主循环 (Main Loop: Moving B to A)

循环直到 B 为空。对于 B 中的每个节点：

Targeting (set_target_a): 找到 A 中最接近且大于 B 元素的节点（即插入点）。如果 B 元素是 A 中最大的，则目标是 A 中最小的元素 (find_min(a))。

Cost Analysis (cost_analysis_a): 计算将 B 元素及其目标节点 (target_node) 移动到堆栈顶部的 最少步数 (costo C_a 和 C_b)。

**优化: 找出通过同时旋转 (RR 或 RRR) 可以减少的共同步数。**
Execution (move_b_to_a): 执行成本最低的操作，将 B 元素推回 A。

### 3. 最终排序 (Final Alignment)

min_on_top: 将 A 中排名为 1 的元素移动到栈顶，完成排序。
## III. 💻 理论计算机科学概念 (CS Theory)

**双向循环链表 (Doubly Circular Linked List)**: Stack A 和 B 的数据结构。

允许 O(1) 的时间和空间复杂度执行 push, swap, rotate 和 reverse_rotate。

**贪婪算法 (Greedy Algorithm)**: 排序策略的核心。

局部最优解 (每一步都选择最便宜的操作) 旨在达到接近全局最优的性能。

**复杂度 (Complexity)**: 评价排序效率的标准。

我们的 Greedy 算法旨在实现 O(N \log N) 级别的性能（移动次数）。

## IV. ⚠️ Manejo de Errores y Norminette

所有错误 (Error\n) 必须在调用 free_errors 后退出，同时清理所有已分配的内存。
**溢出 (Overflow)**: 必须使用 ft_atol 或 long 类型来安全地检查输入是否在 INT_MIN 和 INT_MAX 范围内。
**输入统一**: main 函数必须能够处理单个字符串参数 (./push_swap "1 2 3") 和多个参数 (./push_swap 1 2 3)。
**42 Norminette**: 所有功能必须分成模块化的小函数，并且 main 函数简洁，符合 25 行限制。

