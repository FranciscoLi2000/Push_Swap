# 📚 Push_Swap Project Theory and Implementation (INTP)

This project aims to sort a randomized list of integers on stack A using the minimum number of instructions. The implementation features rigorous modular design, flawless error handling (mandatory part), and employs a Greedy algorithm with cost analysis for optimization.

## I. ⚙️ Architecture Overview

### A. Input & Validation

Ensure input validity (numeric, no duplicates, no overflow) and build the circular doubly linked list.

stack_init, ft_atol, check_input, check_duplicates, check_overflow, handle_input_and_init

### B. Mechanical Operations

Implement the 11 atomic instructions (sa, ra, pa, etc.).

swap, push, rotate, reverse_rotate (and wrappers ss, rr, rrr)

### C. Pre-sorting

Convert actual values into their rank index (1 to N) to simplify the algorithm.

normalize_stack

### D. Sorting Algorithm

Implement an efficient sorting strategy (Greedy/Radix).

sort_three, sort_stacks, move_a_to_b

## II. 🧠 Core Algorithm: The Greedy Strategy

For large stacks (N > 5), the project utilizes a Greedy Algorithm with Cost Analysis to minimize the total sum of rotations for each element.

### 1. Initial Phase

**Normalization (normalize_stack)**: Replace all values with their rank (1 = smallest, N = largest).
**Move A to B (move_a_to_b)**: Move all numbers from A to B, leaving only the 3 largest elements in A.
**Sort 3 (sort_three)**: Sort the remaining 3 elements in A using the minimum 3-instruction set.

### 2. Main Loop (Moving B to A)

The loop continues until B is empty. For every node in B:
**Targeting (set_target_a)**: Find the node in A that is the smallest of the bigger ones (the correct insertion spot). If the B element is the largest overall, the target is the minimum element in A (find_min(a)).
**Cost Analysis (cost_analysis_a)**: Calculate the minimum steps required to bring both the B element and its corresponding target_node to the top of their respective stacks (cost C_a and C_b).
**Optimization**: Identify common moves that can be reduced by using simultaneous rotations (RR or RRR).
**Execution (move_b_to_a)**: Execute the lowest-cost operation, pushing the B element back to A.

### 3. Final Alignment

**min_on_top**: Rotate A to bring the rank 1 element to the top, completing the sort.

## III. 💻 Computer Science Theory

**Doubly Circular Linked List**: The data structure for Stack A and B.
Allows O(1) time and space complexity for push, swap, rotate, and reverse_rotate operations.

**Greedy Algorithm**: The core of the sorting strategy.
Choosing the locally optimal move (the cheapest operation) at each step aims to achieve a near-globally optimal solution.

**Complexity**: The standard for evaluating sorting efficiency.
Our Greedy algorithm aims for O(N \log N) level performance (number of moves).

## IV. ⚠️ Error Handling and Norminette

All errors (Error\n) must exit after calling `free_errors`, which cleans up all allocated memory.
**Overflow**: You must use ft_atol or the long type to safely check if input falls within the INT_MIN and INT_MAX range.
**Input Unification**: The main function must handle both single string arguments (./push_swap "1 2 3") and multiple arguments (./push_swap 1 2 3).
**Norminette**: All functionality must be modularized into small functions, and the main function must be concise (max 25 lines).

