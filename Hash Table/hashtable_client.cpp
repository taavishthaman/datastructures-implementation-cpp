#include<iostream>
#include "hashtable.h"
using namespace std;

int main(){
    Hashtable h;
    h.insert("Apple", 100);
    h.insert("Orange", 130);
    h.insert("Banana", 150);
    h.insert("Grapes", 170);
    //Rehashing of map
    h.insert("Pineapple", 250);
    h.insert("Coconut", 80);
    h.print();
    //Searching a key
    int * value = h.search("Pineapple");
    if(value != NULL){
        cout<<*value<<endl;
    }
    else{
        cout<<"Item does not exist"<<endl;
    }
    //Deleting a key
    h.erase("Pineapple");
    h.print();
}