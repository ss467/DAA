#include<iostream>

using namespace std;

void display_set(int subset){
    for(int bit_no=0;bit_no<=10;bit_no++){
        if((subset) & (1<<bit_no)){
            cout<<bit_no+1<<" ";
        }
    }
}

void remove(int& subset,int n){
    subset = (subset ^ (1 << (n-1)));
}

void add(int& subset,int n){
    subset = (subset ^ (1 << (n-1)));
}

int main(){
    int subset=15;
    remove(subset,2);
    add(subset, 5);
    display_set(subset);
    return 0;
}