#include<iostream>
#include<string>
#include "vector.h"
using namespace std;

int main(){
    Vector v;
    for(int i=1; i<=5; i++){
        v.push_back(i);
    }
    cout<<"Capacity: "<<v.getCapacity()<<" Size: "<<v.getSize()<<endl;
    for(int i=6; i<=15; i++){
        v.push_back(i);
    }
    cout<<"Capacity: "<<v.getCapacity()<<" Size: "<<v.getSize()<<endl;

    while(!v.isEmpty()){
        cout<<v.get_back()<<", ";
        v.pop_back();
    }
}