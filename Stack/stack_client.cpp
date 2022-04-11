#include<iostream>
#include "stack.h"
using namespace std;

int main(){
    Stack s;

    //11 does not go inside the stack since max size of stack is 10.
    for(int i=1; i<=11; i++){
        s.push(i);
    }

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}