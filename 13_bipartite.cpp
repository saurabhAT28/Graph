/*
Bipartite Graph

If only two colors are used in a graph then graph is called as bipartite graph

Odd Cycle=No bipartite
Even Cycle=Bipartite

In this code:
1<=node value
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool flag=false;

void dfs(int src,int par,int col,vector<int>g[],vector<int>&vis){
    // We are also storing the color of the node in visited
    vis[src]=col;

    for(auto x:g[src]){
        if(!vis[x]){
            // If x is not visited
            dfs(x,src,3-col,g,vis);
        }
        else if(x!=par && vis[x]==col){
            // If x is visited then x should not be parent 
            // Color of current node and color of visited should not be same
            flag=true;
            break;
        }
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

    vector<int>vis(v+1);
    dfs(1,0,1,g,vis);

    if(flag)
        cout<<"Not Bipartite";
    else
        cout<<"Bipartite";

    return 0;
}

/*
Bipartite
6 5
1 4
2 4
2 5
3 5
3 6

Not Bipartite
6 6
1 4
2 4
2 5
3 5
3 6
1 2

*/
