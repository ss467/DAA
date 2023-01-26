#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int i,j;

int minCoins(int max, int coins[], int n){
    vector<vector<int>>T(n, vector<int>(max+1));
    for(i=0;i<n;i++){
        for(j=0;j<=max;j++){
            if(coins[i]==1){
                T[i][j]=j;
            }else if(j>=coins[i]){
                T[i][j]=min(1+T[i][j-coins[i]],T[i-1][j]);
            }else{
                T[i][j]=T[i-1][j];
            }
        }
    }
    cout<<"Table"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<=max;j++){
            cout<<T[i][j]<<"\t";
        }
        cout<<endl;
    }

    return T[n-1][max];
}

int main(){
    int max=11;
    int n=4;
    int coins[]={9,6,5,1};
    sort(coins,coins+n);
    cout<<"\nans "<<minCoins(max,coins,n)<<endl;
    return 0;
}