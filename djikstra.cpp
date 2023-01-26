#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

/*vector<int> dijikstra(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> dist(V, INT_MAX);
        pq.push({0,S});
        dist[S]=0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                if(dis+edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis+edgeWeight;
                    pq.push({dis+edgeWeight,adjNode});
                }
            }
        }
        return dist;
}*/


/*vector<int> dijikstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(V,INT_MAX);
    dist[S]=0;
    pq.push({0,S});
    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it: adj[node]){
            int adjNode=it[0];
            int edgeWeight=it[1];
            if(dis+edgeWeight < dist[adjNode]){
                dist[adjNode]=edgeWeight+dis;
                pq.push({dis+edgeWeight,adjNode});
            }
        }
    }
    return dist;
}*/


vector<int> dijikstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int> dist(V,INT_MAX);
    pq.push({0,S});
    dist[S]=0;

    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it: adj[node]){
            int adjNode=it[0];
            int edgeWeight=it[1];
            if(dis+edgeWeight<dist[adjNode]){
                dist[adjNode]=dis+edgeWeight;
                pq.push({dis+edgeWeight,adjNode});
            }
        }
    }
    return dist;
}
int main(){
    int V=3, E=3, S=0; 
    vector<vector<int>> adj[3]; 
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};

    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);
    
    vector<int> res = dijikstra(V, adj, S); 

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}