/*
Connected Components
With starting node is 1

For 0
g[v]
vis[v]
run loop from [1,v);
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int src,vector<int>&vis,vector<int>g[]){
    vis[src]=1;
    // cout<<src<<" ";
    for(auto x:g[src]){
        if(!vis[x])
            dfs(x,vis,g);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v,e;
    cin>>v>>e;

    vector<int>g[v+1];

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout<<"Adj List of a Graph:\n";
    for(int i=1;i<=v;i++){
        cout<<i<<" --> ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"*********************\n";

    int count=0;
    vector<int>vis(v+1);
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            dfs(i,vis,g);
            count++;
        }
    }

    cout<<"Total connected component: "<<count<<endl;

    return 0;
}

/*
9 6
1 2
2 3
4 5
5 6
7 8
8 9
*/