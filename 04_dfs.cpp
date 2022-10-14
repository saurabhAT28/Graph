/*
DFS of a Graph

                0
            /       \
           1         2
          / \       / 
         5   4     3

0 2 3 1 4 5

                0
            /       \
           1         2
          / \       / 
         5---4     3


*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int src,vector<int>&vis,vector<int>g[]){
    vis[src]=1;
    cout<<src<<" ";
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

    vector<int>vis(v);
    dfs(0,vis,g);

    return 0;
}

/*
6 5
0 2
2 3
0 1
1 4
1 5

*/

/*
6 6
0 2
2 3
0 1
1 4
1 5
4 5
*/