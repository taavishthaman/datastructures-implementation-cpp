#include<iostream>
#include "queue.h"
using namespace std;

int main(){
    Queue q;
    for(int i=1; i<=6; i++){
        q.push(i);
    }

    while(!q.isEmpty()){
        cout<<q.get_front()<<" ";
        q.pop();
    }
}