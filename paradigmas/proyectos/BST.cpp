#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T> struct Node {
  Node *left;
  Node *right;
  T data;

  Node(T value) {
    data = value;
    left = right = nullptr;
  }
};

template <class T> class BST {
private:
  Node<T> *root;

  Node<T> *insert(T value, Node<T> *temp) {
    if (temp == nullptr) {
      temp = new Node<T>(value);
    } else if (value < temp->data) {
      temp->left = insert(value, temp->left);
    } else {
      temp->right = insert(value, temp->right);
    }

    return temp;
  }

  void inOrder(Node<T> *temp) {
    if (temp == nullptr) {
      return;
    }
    inOrder(temp->left);
    cout << temp->data << endl;
    inOrder(temp->right);
  }

  void preOrder(Node<T> *temp) {
      if (temp == nullptr) {
          return;
      }
      cout << temp->data << endl; 
      preOrder(temp->left);       
      preOrder(temp->right);      
  }

  void postOrder(Node<T> *temp) {
      if (temp == nullptr) {
          return;
      }
      postOrder(temp->left);      
      postOrder(temp->right);     
      cout << temp->data << endl;  
  }

public:
  BST() { root = nullptr; }

  void insert(T value) { root = insert(value, root); }

  void inorder() { inOrder(root); }

  friend ostream &operator<<(ostream &os, BST<T> &bst) {
    bst.inorder();
    return os;
  }
};

int main() {
  BST<int> tree;

  tree.insert(14);
  tree.insert(18);
  tree.insert(5);
  tree.insert(19);
  tree.insert(7);
  tree.insert(2);
  tree.insert(13);
  tree.insert(3);

  cout << tree;
}
