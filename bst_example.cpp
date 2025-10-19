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

  // Insert (loop)
  void Insert(const T& value) {
    TreeNode* newNode = new TreeNode(value);

    if (root == nullptr) {
      root = newNode;
      return;
    }

    TreeNode* current = root;

    while (true) {
      if (current->data > value) {
        if (current->left == nullptr) {
          current->left = newNode;
          return;
        } else {
          current = current->left;
        }
      } else if (current->data < value) {
        if (current->right == nullptr) {
          current->right = newNode;
          return;
        } else {
          current = current->right;
        }
      } else {
        return;
      }
    }
  }

  // Remove (loop)
  void Remove(const T& value) {
    if (root == nullptr) {
      return;
    }


    TreeNode* current = root;
    TreeNode* parent = nullptr;
    if (current->data == value) {
      if (current->left != nullptr && current!= nullptr) {
        current->left->right = current->right;
        delete current;
      } else {
        delete current;
      }
    }

    while (true) {
      if (current->data > value) {
        parent = current;
        current = current->left;
        if (current->data == value) {

        }
      } else if (current->data < value) {
        parent = current;
        current = current->right;
        if (current->data == value) {

        }
      }
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
