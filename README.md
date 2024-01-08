# C - Binary Trees

This project is part of the curriculum of Holberton School. It's focused on understanding and implementing binary trees in C. The project was completed by the team of Christophe Marie Reine and Nicolas Taillepierre.

## Description

Binary trees are a fundamental data structure in computer science, used in various applications for efficient data storage and retrieval. This project covers various types of binary trees, including binary search trees, AVL trees, and max binary heaps, as well as their common operations.

### Learning Objectives

- Understand what a binary tree is.
- Differentiate between binary trees and Binary Search Trees (BSTs).
- Analyze the time complexity advantages of binary trees compared to linked lists.
- Comprehend the concepts of depth, height, and size in a binary tree.
- Learn about the different traversal methods: pre-order, in-order, post-order.
- Understand what complete, full, perfect, and balanced binary trees are.

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`.
- All files will be compiled on Ubuntu 20.04 LTS using `gcc` with options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All files should end with a new line.
- Code should use the Betty style for checks.
- No more than 5 functions per file.
- Standard library allowed.
- The prototypes of all functions should be included in the header file `binary_trees.h`.
- Header files should be include guarded.

## Installation & Usage

Clone the repository and compile the code with the following commands:

```bash
git clone [repository link]
gcc -Wall -Werror -Wextra -pedantic *.c -o binary_trees
```

Run the program:

```bash
./binary_trees
```

## Data Structures
The following structures are used in this project:

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
```

## Tasks
The project consists of multiple tasks, ranging from creating a new node in a binary tree to implementing various tree traversal methods. Each task is an opportunity to practice and understand binary tree operations better.

## Authors
Christophe 'Craig' Marie Reine
Nicolas Taillepierre
