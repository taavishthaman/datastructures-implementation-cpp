#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data = data;
    }
};

class BinaryTree{
    Node * root;
public:
    BinaryTree(){
        root = NULL;
    }

    Node * preorder_build(){
        int d;
        cin>>d;
        if(d == -1){
            return NULL;
        }
        Node * n = new Node(d);
        n->left = preorder_build();
        n->right = preorder_build();
        return n;
    }

    void preorder(Node * root){
        if(root == NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
};