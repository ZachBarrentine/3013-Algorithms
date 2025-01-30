/*****************************************************************************
*                    
*  Author:           Zachary Barrentine
*  Email:            zlbarrentine0427@my.msutexas.edu
*  Label:            A03
*  Title:            Binary Search Tree Delete
*  Course:           CMPS 3013
*  Semester:         Spring 2025
* 
*  Description:
*        This program adds a delete function to the binary search tree class.
*
*  Usage:
*       - Compile and run the program.
*       - The program will output the tree before and after deleting a node.
* 
*  Files:            
*       BST_Delete.cpp   : driver program
*****************************************************************************/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int x) {
    data = x;
    left = right = nullptr;
  }
};

class Bst {
private:
  Node *root;

  void _insert(Node *&sub_root, int x) {
    if (sub_root == nullptr) {
      sub_root = new Node(x);
    } else {
      if (x < sub_root->data) {
        _insert(sub_root->left, x);
      } else {
        _insert(sub_root->right, x);
      }
    }
  }

/**
 * _deleteNode
 *
 * Description:
 *     Recursively deletes a node with a specified value from the tree.
 *
 * Params:
 *     Node*& sub_root : Reference to the subtree where deletion is performed.
 *     int key : Value to be deleted.
 *
 * Returns:
 *     Node* : Updated subtree after deletion.
 */
  Node* _deleteNode(Node* &sub_root, int key) {
    if (!sub_root) return sub_root;
    if (key < sub_root->data) {
      sub_root->left = _deleteNode(sub_root->left, key);
    } else if (key > sub_root->data) {
      sub_root->right = _deleteNode(sub_root->right, key);
    } else {
      if (!sub_root->left) {
        Node* temp = sub_root->right;
        delete sub_root;
        return temp;
      } else if (!sub_root->right) {
        Node* temp = sub_root->left;
        delete sub_root;
        return temp;
      }
      Node* temp = sub_root->right;
      while (temp->left) temp = temp->left;
      sub_root->data = temp->data;
      sub_root->right = _deleteNode(sub_root->right, temp->data);
    }
    return sub_root;
  }

  void _print(Node *root) {
    if (!root) {
      return;
    }
    _print(root->left);
    cout << root->data << " ";
    _print(root->right);
  }

public:
  Bst() { root = nullptr; }
  void insert(int x) {
    _insert(root, x);
  }
  void deleteNode(int x) {
    root = _deleteNode(root, x);
  }
  bool search() { return false; }
  void print() { 
    _print(root);
    cout << endl;
  }
};

int main() {
  Bst tree;
  tree.insert(8);
  tree.insert(3);
  tree.insert(1);
  tree.insert(11);
  tree.insert(7);
  tree.insert(15);
  
  tree.print();
  cout << "\nNow deleting 3\n";
  tree.deleteNode(3);
  tree.print();

  cout << "\nNow deleting 11\n";
  tree.deleteNode(11);
  tree.print();
}