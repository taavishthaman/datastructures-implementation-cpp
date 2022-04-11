#include<iostream>
#include "binary_search_tree.cpp"
using namespace std;

int main(){
    BinarySearchTree bst;
    Node * root = bst.insert();
    bst.inorder(root);
    cout<<endl;
    bst.removeNode(root, 0);
    bst.inorder(root);
}