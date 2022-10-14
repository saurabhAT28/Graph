/*
Dijkstra's Algorithm
To find shortest path in Acyclic graph
Using min heap

If weight is negative then dijkstra is not going to work properly

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printVector(vector<int>v){
    int n=v.size();
    for(int i=0;i<n;i++){
        cout<<i<<" --> "<<v[i]<<"\n";
    }
}

void dijkstraAlgo(int source,int n,vector<pair<int,int>>g[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
    vector<int>dist(n,INT_MAX);

    dist[source]=0;
    minHeap.push({0,source});

    while(!minHeap.empty()){
        int distance=minHeap.top().first;
        int prev=minHeap.top().second;
        minHeap.pop();

        vector<pair<int,int>> :: iterator it;
        for(auto it:g[prev]){
            int next=it.first;
            int nextDistance=it.second;

            if(dist[next]>dist[prev]+nextDistance){
                dist[next]=dist[prev]+nextDistance;
                minHeap.push({dist[next],next});
            }
        }
    }

    cout<<"The distance from source "<<source<<"\n";
    printVector(dist);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,e,source;
    cin>>n>>e>>source;

    vector<pair<int,int>>g[n];

    for(int i=1;i<=e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }

    cout<<"Adj List of a Graph:\n";
    for(int i=0;i<n;i++){
        cout<<i<<" --> ";
        for(int j=0;j<g[i].size();j++){
            cout<<"{"<<g[i][j].first<<","<<g[i][j].second<<"}";
        }
        cout<<"\n";
    }
    cout<<"*********************\n";

    dijkstraAlgo(source,n,g);

    return 0;
}

/*
5 6 0
0 1 2
1 4 5
0 3 1
1 2 4
2 3 3
2 4 1

5 6 1
0 1 2
1 4 5
0 3 1
1 2 4
2 3 3
2 4 1


*/





