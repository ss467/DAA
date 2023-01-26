#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


int partition(int arr[10], int l, int h){
    int i=l;
    int j=h;
    int pivot=arr[l];
    do{
    do{
        i++;
    }while(arr[i]<=pivot);
    do{
        j--;
    }while(arr[j]>pivot);
    if(i<j){
        swap(&arr[i],&arr[j]);
    }
    }while(i<j);
    swap(&arr[j],&arr[l]);

    return j;

}

void qs(int arr[10], int l, int h){
    int j;
    if(l<h){
        j=partition(arr,l,h);
        qs(arr,l,j);
        qs(arr,j+1,h);
    }
}

int main(){
    int arr[10] = {10,5,35,22,5,10,123456};
    int n=7;
    qs(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}