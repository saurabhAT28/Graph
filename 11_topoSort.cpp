/*
Topological Sort
Using DFS

Requirment
1. Use in only Directed Graph
2. Acyclic Graph

Indegree: No. of edes coming on a node

Print nodes with 0 indegree and remove edges of that node

0<=value of node

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printVector(vector<int>v){
    int n=v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
}

void dfs(int src,vector<int>&vis,vector<int>g[],vector<int>&ans){
    vis[src]=1;
    ans.push_back(src);
    for(auto x:g[src]){
        if(!vis[x])
            dfs(x,vis,g,ans);
    }
}

vector<int> topoSort(int v,vector<int>g[]){
    vector<int>vis(v,0);
    vector<int>ans;

    for(int i=0;i<v;i++){
        if(!vis[i])
            dfs(i,vis,g,ans);
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v,e;
    cin>>v>>e;

    vector<int>g[v];

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }

    cout<<"Adj List of a Graph:\n";
    for(int i=0;i<v;i++){
        cout<<i<<" --> ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"*********************\n";

    vector<int>ans=topoSort(v,g);
    reverse(ans.begin(),ans.end());
    printVector(ans);
    return 0;
}

/*
4 3
1 0
2 0
3 0

*/