#include<iostream>
#include "heap.h";
using namespace std;

int main(){
    Heap h(0);
    for(int i=5; i>= 0; i--){
        h.push(i);
    }

    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }
}