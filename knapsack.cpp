#include<iostream>

using namespace std;

void knapSack(int W, int wt[], int val[], int n){
    int dp[n+1][W+1];
    for(int i=0; i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(j>=wt[i-1]){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int i=n, j=W;
    while(i>0&&j>0){
        if(dp[i][j]==dp[i-1][j]){
            cout<<"Object "<<i--<<" 0";
        }else{
            cout<<"Object "<<i--<<" 1";
            j=j-wt[i];
        }
    }
    cout<<"Total profit is "<<dp[n][W]<<endl;
}

int main()
{
    int val[10],wt[10],n,W;
   cout<<"Enter number of objects "<<endl;
   cin>>n;
   cout<<"Enter capacity "<<endl;
   cin>>W;
    cout<<"Enter value and weight for each:\n";
    for(int i=0;i<n;i++)
        cin>>val[i]>>wt[i];
    knapSack(W, wt, val, n);
    
    return 0;
}