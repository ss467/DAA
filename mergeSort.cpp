#include<iostream>

using namespace std;

void merge(int arr[10], int l, int mid, int h){
    int i=l;
    int k=l;
    int j=mid+1;
    int B[100];
    while(i<=mid && j<=h){
        if(arr[i]<arr[j]){
            B[k++]=arr[i++];
        }else{
            B[k++]=arr[j++];
        }
    }
    for(;i<=mid;i++){
        B[k++]=arr[i];
    }
    for(;j<=h;j++){
        B[k++]=arr[j];
    }
    for(i=l;i<=h;i++){
        arr[i]=B[i];
    }
}

void mergesort(int arr[10], int l, int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main(){
    int arr[10]={5,8,10,9,2,1};
    int n=6;
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}