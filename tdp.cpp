#include<iostream>

using namespace std;

int dist[10][10]={
    {0,10,15,20},
    {5,0,9,10},
    {6,13,0,12},
    {8,8,9,0}
};

int n=4;

#define INT_MAX 9999999

int VISITED_ALL = (1<<n)-1;

int tsp(int mask, int pos){
    if(mask==VISITED_ALL){
        return dist[pos][0];
    }

    int ans = INT_MAX;

    for(int city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int newAns = dist[pos][city] + tsp(mask|(1<<city),city);
            ans = min(newAns,ans);
        }
    }
    return ans;
}

int main(){
    cout<<"Minimum distance "<<tsp(1,0)<<endl;
    return 0;
}