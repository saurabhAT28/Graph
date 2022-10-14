/*
Graph
Non Linear DS
V=vertices
E=Edges

Adjecency List:
TC=O(V+E)
SC=O(V+E)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v,e;
    cin>>v>>e;

    vector<int>g[v+1];

    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1;i<=v;i++){
        cout<<i<<" --> ";
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/*
5 4
1 2
1 5
1 3
3 4
*/