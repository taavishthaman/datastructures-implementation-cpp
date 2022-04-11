#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Node{
public:
    char ch;
    unordered_map<char, Node*> m;
    bool isTerminal;
    Node(char ch){
        this->ch = ch;
        isTerminal = false;
    }
};

class Trie{
    Node * root;
public:
    Trie(){
        root = new Node('\0');
    }

    void insert(string s){
        Node * temp = root;
        for(char ch : s){
            if(temp->m.count(ch) == 0){
                temp->m[ch] = new Node(ch);
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string s){
        Node * temp = root;
        for(char ch : s){
            if(temp->m.count(ch) == 0){
                return false;
            }
            else{
                temp = temp->m[ch];
            }
        }
        return temp->isTerminal;
    }
};