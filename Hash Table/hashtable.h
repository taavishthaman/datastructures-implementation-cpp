#include<iostream>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node * next;
    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class Hashtable{
    Node ** table;
    int cs;
    int ts;

    int hashFn(string key){
        int idx = 0;
        int p = 1;
        for(char ch : key){
            idx += (ch * 29) % ts;
            p = (p * 29) % ts;
        }
        return idx % ts;
    }

    void rehash(){
        Node ** oldTable = table;
        int oldSize = ts;
        ts = 2 * ts + 1;
        cs = 0;
        table = new Node*[ts];
        for(int i=0; i<ts; i++){
            table[i] = NULL;
        }

        for(int i=0; i<oldSize; i++){
            Node * temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }

        delete [] oldTable;
    }
public:
    Hashtable(int default_size=7){
        table = new Node*[default_size];
        cs = 0;
        ts = default_size;
        for(int i=0; i<ts; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){
        int idx = hashFn(key);
        Node * n = new Node(key, val);
        n->next = table[idx];
        table[idx] = n;
        cs ++;

        float load_factor = cs/(float)ts;
        if(load_factor >= 0.7){
            rehash();
        }
    }
    
    int* search(string key){
        int idx = hashFn(key);
        Node * temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){
                return &temp->val;
            }
            temp = temp->next;
        }
        return NULL;
    }
    
    void erase(string key){
        int idx = hashFn(key);
        Node * temp = table[idx];
        if(temp->key == key){
            Node * n = temp;
            temp = temp->next;
            n->next = NULL;
            table[idx] = temp;
            delete n;
        }
        else{
            while(temp != NULL){
                if(temp->next->key == key){
                    if(temp->next->next == NULL){
                        Node * n = temp->next;
                        temp->next = NULL;
                        delete n;
                    }
                    else{
                        Node * n = temp->next;
                        temp->next = temp->next->next;
                        n->next = NULL;
                        delete n;
                    }
                }
                temp=temp->next;
            }
        }
    }
    
    void print(){
        cout<<"-----------------------"<<endl;
        for(int i=0; i<ts; i++){
            cout<<"Bucket "<<i<<"-->";
            Node * temp = table[i];
            while(temp != NULL){
                cout<<temp->key<<"-->";
                temp = temp->next;
            }
            cout<<endl;
        }
        cout<<"-----------------------"<<endl;
    }
};