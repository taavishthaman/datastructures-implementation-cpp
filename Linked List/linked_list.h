#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
    }

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class LinkedList{
    Node * head;
    Node * tail;
public:
    LinkedList(){
        head = tail = NULL;
    }

    void push_front(int data){
        if(head == NULL){
            Node * n = new Node(data);
            head = tail = n;
        }
        else{
            Node * n = new Node(data);
            n->next = head;
            head = n;
        }
    }

    void push_back(int data){
        if(head == NULL){
            Node * n = new Node(data);
            head = tail = n;
        }
        else{
            Node * n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }

    void remove_front(){
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void insert_at(int val, int pos){
        if(pos == 0){
            push_front(val);
        }
        else{
            Node * temp = head;
            int count = 0;
            while(count < pos-1){
                temp = temp->next;
                count++;
            }
            Node * n = temp->next;
            Node * nn = new Node(val);
            temp->next = nn;
            nn->next = n;
            if(n == NULL){
                tail = nn;
            }
        }
    }

    void remove_at(int pos){
        if(pos == 0){
            remove_front();
        }
        else{
            Node * temp = head;
            int count = 0;
            while(count < pos-1){
                temp = temp->next;
                count++;
            }
            Node * n = temp->next;
            if(n->next == NULL){
                tail = temp;
                delete n;
                temp->next = NULL;
            }
            else{
                temp->next = n->next;
                n->next = NULL;
                delete n;
            }
        }
    }

    void print(){
        Node * temp = head;
        while(temp != NULL){
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<endl;
    }

    ~LinkedList(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }
};