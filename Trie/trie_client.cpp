#include<iostream>
#include<vector>
#include "trie.h"
using namespace std;

int main(){
    Trie t;
    vector<string> v;
    v.push_back("hello");
    v.push_back("hell");
    v.push_back("plant");
    v.push_back("planet");
    v.push_back("system");
    for(string s : v){
        t.insert(s);
    }
    cout<<t.search("hello")<<endl;
}