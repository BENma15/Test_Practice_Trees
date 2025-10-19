#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class BinarySearchTree {
 private:
  // Node struct
  struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
  };

  // Root pointer
  TreeNode* root;

 public:
  // Constructor
  BinarySearchTree() : root(nullptr) {}

  // Destructor
  ~BinarySearchTree() {
    // delete all nodes in the tree
    // let's implement this after we've learned recursion
  }

  // Insert
  void Insert(const T& value) {
    if (root == nullptr) {
      root = new TreeNode(value);
      return;
    }

    TreeNode* current = root;
    while (true) {
      if (value < current->data) {
        if (current->left == nullptr) {
          current->left = new TreeNode(value);
          break;
        }
        current = current->left;
      } else if (value > current->data) {
        if (current->right == nullptr) {
          current->right = new TreeNode(value);
          break;
        }
        current = current->right;
      } else {
        break;  // Value already exists, do nothing
      }
    }
  }

  // Remove
  void Remove(const T& value) {
    if (!root) return;

    TreeNode* current = root;
    TreeNode* parent = nullptr;
    while (true) {
      if (!current) return;  // Value not found
      if (value < current->data) {
        parent = current;
        current = current->left;
      } else if (value > current->data) {
        parent = current;
        current = current->right;
      } else {  // Value found
        break;
      }
    }

    bool at_left = parent ? (parent->left == current) : false;
    if (!current->left && !current->right) {
      // Case 1: No children
      if (root == current)
        root = nullptr;
      else if (at_left)
        parent->left = nullptr;
      else
        parent->right = nullptr;
      delete current;

    } else if (!current->left) {
      // Case 2: Only right child
      TreeNode* temp = current->right;
      if (root == current)
        root = temp;
      else if (at_left)
        parent->left = temp;
      else
        parent->right = temp;
      delete current;

    } else if (!current->right) {
      // Case 3: Only left child
      TreeNode* temp = current->left;
      if (root == current)
        root = temp;
      else if (at_left)
        parent->left = temp;
      else
        parent->right = temp;
      delete current;

    } else {
      // Case 4: Two children
      // Find the minimum node in the right subtree
      TreeNode* min_parent = current;
      TreeNode* min = current->right;
      while (min->left) {
        min_parent = min;
        min = min->left;
      }
      // Replace current's data with min's data
      current->data = min->data;
      // Remove the min node from the right subtree
      if (min_parent == current) {
        // min is the immediate right child
        min_parent->right = min->right;
      } else {
        min_parent->left = min->right;
      }
      delete min;
    }
  }
};

int main() {
  // Create a BinarySearchTree object with int type
  BinarySearchTree<int> bst;

  std::cout << "Binary Search Tree Template Implementation" << std::endl;
  std::cout << "==========================================" << std::endl;

  // Test the BST Insert and Remove operations:
  /*
          70
        /    \
      30      90
     /  \    /  \
   20   60  80  100
        /
      40
        \
        50
  */
  std::cout << "Inserting values: 70, 30, 90, 20, 60, 80, 100, 40, 50"
            << std::endl;
  bst.Insert(70);
  bst.Insert(30);
  bst.Insert(90);
  bst.Insert(20);
  bst.Insert(60);
  bst.Insert(80);
  bst.Insert(100);
  bst.Insert(40);
  bst.Insert(50);

  std::cout << "Removing value 30..." << std::endl;
  bst.Remove(30);
  // After removing 30, the tree structure should be:
  /*
          70
        /    \
      40      90
     /  \    /  \
   20   60  80  100
        /
      50
  */

  return 0;
}
