#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> arr;
    int cs;
    int ms;
    int tos;

public:
    Stack(int default_size = 10){
        cs = 0;
        ms = default_size;
        tos = -1;
    }

    bool isFull(){
        return cs == ms;
    }

    void push(int val){
        if(!isFull()){
            arr.push_back(val);
            tos++;
            cs++;
        }
    }

    bool isEmpty(){
        return cs == 0;
    }

    void pop(){
        if(!isEmpty()){
            tos--;
            cs--;
        }
    }

    int top(){
        if(!isEmpty()){
            return arr[tos];
        }
        return -1;
    }
};