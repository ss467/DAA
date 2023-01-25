#include<iostream>

using namespace std;

#define INT_MAX 999999


int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

int n=4;


int VISITED_ALL = (1<<n) - 1;
int ans=INT_MAX;

int tsp(int mask, int pos){
    if(mask==VISITED_ALL){
        return dist[pos][0];
    }

    for(int city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int newAns = dist[pos][city] + tsp(mask|(1<<city),pos);
            ans = min(ans,newAns);
        }
    }

    return ans;
}

int main(){
    cout<<"Minumu distance "<<tsp(1,0)<<endl;
    return 0;
}