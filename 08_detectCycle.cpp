/*
Detect Cycle in undirected graph

*/



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool dfs(int src,int par,vector<int>&vis,vector<int>g[]){
    vis[src]=1;

    for(auto x:g[src]){
        if(!vis[x]){
            if(dfs(x,src,vis,g))
                return true;
        }
        else if(x!=par)
            return true;
    }
    return false;
}

bool isCyclic(int v,vector<int>g[]){
    vector<int>vis(v,0);

    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,g))
                return true;
        }
    }
    return false;
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
        g[y].push_back(x);
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

    bool flag=isCyclic(v,g);
    cout<<"Cycle: "<<flag<<endl;


    return 0;
}

/*
4 3
0 1
1 2
2 3

4 4
0 1
1 2
2 3
3 0
*/