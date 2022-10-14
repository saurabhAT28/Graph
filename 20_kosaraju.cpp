/*
Kosaraju Algorithm
Count the Strongly Connected Components

Apply dfs from reverse

Steps:
1. Find topo sort (not exactly topo sort)
3. Reverse Graph (Transpose)
3. DFS in reverse graph
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

void dfs(int src,stack<int>&st,vector<int>&vis,vector<int>g[]){
    vis[src]=1;
    for(auto x:g[src]){
        if(!vis[x])
            dfs(x,st,vis,g);
    }
    st.push(src);
}

void revDFS(int src,vector<int>&vis,vector<int>transpose[]){
    vis[src]=1;
    cout<<src<<" ";
    for(auto x:transpose[src]){
        if(!vis[x])
            revDFS(x,vis,transpose);
    }
}

void kosaraju(int N,vector<int>g[]){
    vector<int>vis(N,0);

    // Step 1
    stack<int>st;
    for(int i=0;i<N;i++){
        if(!vis[i])
            dfs(i,st,vis,g);
    }

    // Step 2
    vector<int>transpose[N];
    for(int i=0;i<N;i++){
        vis[i]=0;
        for(auto it:g[i])
            transpose[it].push_back(i);
    }

    // Step 3
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            cout<<"SCC: ";
            revDFS(node,vis,transpose);
            cout<<endl;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,e;
    cin>>N>>e;

    vector<int>g[N];

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }

    cout<<"Adj List of a Graph:\n";
    for(int i=0;i<N;i++){
        cout<<i<<" --> ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"*********************\n";

    kosaraju(N,g);

    return 0;
}

/*
5 5
0 1
1 3
3 4
1 2
2 0

*/