#include<iostream>
#include "binary_tree.cpp"
using namespace std;

int main(){
    BinaryTree bt;
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    Node * root = bt.preorder_build();
    bt.preorder(root);
}