/*
Shortest path in DAG

Steps:
1. Topo Sort

*/




#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printVector(vector<int>v){
    int n=v.size();
    for(int i=0;i<n;i++){
        (v[i]==1e9)?cout<<"INF ":cout<<v[i]<<" ";
    }
}

void findTopoSort(int node,vector<int>&vis,stack<int>&st,vector<pair<int,int>>g[]){
    vis[node]=1;
    for(auto it:g[node]){
        if(!vis[it.first])
            findTopoSort(it.first,vis,st,g);
    }
    st.push(node);
}




void shortestPath(int src,int n,vector<pair<int,int>>g[]){
    // Step 1
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i])
            findTopoSort(i,vis,st,g);
    }

    vector<int>dist(n);
    dist[0]=0;
    for(int i=1;i<n;i++)
        dist[i]=INT_MAX;
    
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(dist[node]!=INT_MAX){
            for(auto it:g[node]){
                if(dist[node]+it.second<dist[it.first])
                    dist[it.first]=dist[node]+it.second;
            }
        }
    }

    printVector(dist);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,e;
    cin>>n>>e;

    vector<pair<int,int>>g[n];

    for(int i=1;i<=e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u].push_back({v,wt});
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

    shortestPath(0,n,g);


    return 0;
}



/*
6 7
0 1 2
0 4 1
1 2 3
2 3 6
4 2 2
4 5 4
5 3 1

*/