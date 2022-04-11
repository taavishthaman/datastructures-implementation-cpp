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
        left = right = NULL;
    }
};

class BinarySearchTree{
    Node * root;
public:
    BinarySearchTree(){
        root = NULL;
    }
    
    Node * insert_rec(Node * root, int val){
        if(root == NULL){
            Node * n = new Node(val);
            return n;
        }
        if(val < root->data){
            root->left = insert_rec(root->left, val);
        }
        else{
            root->right = insert_rec(root->right, val);
        }
        return root;
    }

    Node* insert(){
        vector<int> v = {5, 3, 1, 8, 9, 0, 6, 7};
        for(int x : v){
            root = insert_rec(root, x);
        }
        return root;
    }

    void inorder(Node * node){
        if(node == NULL){
            return;
        }
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
    
    Node * findMin(Node * root){
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        return findMin(root->left);
    }
    
    Node * removeNode(Node * root, int key){
        if(root == NULL){
            return NULL;
        }
        if(key < root->data){
            root->left = removeNode(root->left, key);
        }
        else if(key > root->data){
            root->right = removeNode(root->right, key);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
            }
            else if(root->left == NULL){
                Node * temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL){
                Node * temp = root;
                root = root->left;
                delete temp;
            }
            else{
                Node * minNode = findMin(root->right);
                root->data = minNode->data;
                root->right = removeNode(root->right, root->data);
            }
        }
        return root;
    }
};