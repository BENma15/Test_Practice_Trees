# Binary Search Tree Implementation Exercise

This folder contains a template for implementing a Binary Search Tree (BST) data structure in C++. 

## Files

- `bst_example.cpp` - Template file with TODO comments for BST implementation
- `Makefile` - Build configuration
- `.vscode/` - VS Code debugging configuration


## Exercise Instructions

### Step 1: Complete the Node Structure
Implement the `Node` template struct

### Step 2: Implement the BinarySearchTree Template Class
Complete the following methods:

- `Insert(const T& value)` - Insert a new value
- `Contains(const T& value)` - Search for a value
- `Traverse()` - Print values in sorted order (inorder traversal)
- `Remove(const T& value)` - Remove a value
- `FindMin()` - Return the minimum value in the tree
- `FindMax()` - Return the maximum value in the tree
- `IsEmpty()` - Check if tree is empty

Implement private helper functions as needed

## Key Concepts to Remember

### BST Properties:
- Left subtree contains only values less than the current node
- Right subtree contains only values greater than the current node
- Both left and right subtrees are also BSTs
- No duplicate values (in this implementation)

### Algorithm Hints:
- **Insertion**: Compare with current node, go left if smaller, right if larger, insert the node if not already exists
- **Search (Contains)**: Similar to insertion, return true if found, false if null
- **Traverse (Inorder)**: Left → Current → Right (gives sorted order)
- **FindMin**: Go left until you reach a node with no left child
- **FindMax**: Go right until you reach a node with no right child
- **Deletion (Remove)**: Handle three cases - no children, one child, two children

## Usage

### Compilation
```bash
make
```

### Running
```bash
./bst_example
```

### Debugging in VS Code
1. Open the `binary_search_tree` folder in VS Code
2. Set breakpoints in your code by clicking in the left margin
3. Press F5 or go to Run → Start Debugging
4. The debugger will build and run the program

## Expected Output

When completed correctly, your program should produce:
```
Binary Search Tree Template Implementation
Inorder traversal: 20 30 40 50 60 70 80
Contains 40: true
Contains 90: false
Minimum value: 20
Maximum value: 80
After removing 30:
Inorder traversal: 20 40 50 60 70 80
```

Good luck with your implementation! Remember to test each method thoroughly and use the debugger to trace through your recursive calls.
