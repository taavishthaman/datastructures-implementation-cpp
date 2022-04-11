#include<iostream>
using namespace std;

class Queue{
    int * arr;
    int front;
    int rear;
    int cs;
    int ms;

public:
    Queue(int default_capacity = 5){
        arr = new int[default_capacity];
        cs = 0;
        ms = default_capacity;
        front = 0;
        rear = default_capacity-1;
    }

    bool isEmpty(){
        return cs == 0;
    }

    bool isFull(){
        return cs == ms;
    }

    void push(int val){
        if(!isFull()){
            rear = (rear + 1) % ms;
            arr[rear] = val;
            cs++;
        }
    }

    void pop(){
        if(!isEmpty()){
            front = (front + 1) % ms;
            cs--;
        }
    }

    int get_front(){
        if(!isEmpty()){
            return arr[front];
        }
        return -1;
    }
};