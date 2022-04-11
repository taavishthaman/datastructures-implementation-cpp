#include<iostream>
#include "linked_list.h"
using namespace std;

int main(){
    LinkedList l;

    for(int i=1; i<=4; i++){
        l.push_back(i);
    }
    for(int i=1; i<=4; i++){
        l.push_front(i);
    }

    l.print();
    l.remove_at(7);
    l.print();
    l.insert_at(25, 2);
    l.print();
    l.insert_at(45, 0);
    l.print();
    l.insert_at(65, 9);
    l.print();
}