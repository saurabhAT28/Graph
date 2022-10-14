/*
Detect Cycle in Directed Graph Using DFS

            1--->2
                 |
                 V
            4<---3

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool dfs(int src,vector<int>&vis,vector<int>&ord,vector<int>g[]){
    vis[src]=1;
    ord[src]=1;
    for(auto x:g[src]){
        if(!vis[x]){
            if(dfs(x,vis,ord,g))
                return true;
        }
        else if(ord[x])
            return true;
    }
    ord[src]=0;
    return false;
}

bool isCyclic(int v,vector<int>g[]){
    vector<int>vis(v,0);
    vector<int>ord(v,0);

    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,vis,ord,g))
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

    // Directed Graph
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

    bool flag=isCyclic(v,g);
    cout<<"Cycle: "<<flag<<endl;


    return 0;
}

/*
4 4
0 1
1 2
2 3
3 0
***********
4 3
0 1
1 2
2 3
***********
3 3
1 2
2 3
3 1
*/