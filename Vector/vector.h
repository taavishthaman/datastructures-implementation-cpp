#include<iostream>
using namespace std;

class Vector{
    int * arr;
    int cs;
    int ms;
    int b;
public:
    Vector(int default_size = 10){
        ms = default_size;
        cs = 0;
        b = -1;
        arr = new int[ms];
    }

    void push_back(int val){
        //If current size = maximum size then double the array and do a copying operation
        if(cs == ms){
            int *oldArr = arr;
            arr = new int[2*ms];
            for(int i=0; i<ms; i++){
                arr[i] = oldArr[i];
            }
            ms = 2 * ms;
            delete [] oldArr;
        }
        arr[++b] = val;
        cs++;
    }

    bool isEmpty(){
        return cs == 0;
    }

    void pop_back(){
        if(!isEmpty()){
            cs--;
            b--;
        }
    }

    int get_back(){
        return arr[b];
    }

    int getCapacity(){
        return ms;
    }
    
    int getSize(){
        return cs;
    }
};
