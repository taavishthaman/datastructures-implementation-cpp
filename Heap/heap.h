#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    int size;
    //0 is min heap, 1 is max heap
    bool type;

    void upHeapify(int ci){
        int pi = (ci-1)/2;
        if(!type && ci >= 0 && v[pi] > v[ci]){
            swap(v[pi], v[ci]);
            upHeapify(pi);
        }
        else if(type && ci >= 0 && v[pi] < v[ci]){
            swap(v[pi], v[ci]);
            upHeapify(pi);
        }
    }

    void downHeapify(int pi){
        int ci1 = 2 * pi + 1;
        int ci2 = 2 * pi + 2;
        int m = pi;

        if(!type){
            if(ci1 < v.size() && v[ci1] < v[m]){
                m = ci1;
            }
            if(ci2 < v.size() && v[ci2] < v[m]){
                m = ci2;
            }
        }
        else{
            if(ci1 < v.size() && v[ci1] > v[m]){
                m = ci1;
            }
            if(ci2 < v.size() && v[ci2] > v[m]){
                m = ci2;
            }
        }

        if(m != pi){
            swap(v[pi], v[m]);
            downHeapify(m);
        }
    }
public:
    Heap(bool type){
        size = 0;
        this->type = type;
    }

    void push(int val){
        v.push_back(val);
        size++;
        upHeapify(v.size()-1);
    }

    void pop(){
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        size--;
        downHeapify(0);
    }

    int top(){
        return v[0];
    }

    int get_size(){
        return size;
    }

    bool empty(){
        return v.size() == 0;
    }
};