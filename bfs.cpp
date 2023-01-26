#include<iostream>
using namespace std;

int visited[10];

void dfs(int n, int adj[10][10], int S){
    int i, q[10],u, front=1, rear=1;
    visited[S]=1;
    q[rear]=S;
    while(front<=rear){
        u=q[front];
        front++;
        for(i=1;i<=n;i++){
            if(adj[u][i]==1 && visited[i]==0){
                rear++;
                q[rear]=i;
                visited[i]=1;
            }
        }
    }
}