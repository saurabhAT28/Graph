/*
Weighted Graph Representation

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v,e;
    cin>>v>>e;

    vector<pair<int,int>>g[v];

    for(int i=1;i<=e;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }

    cout<<"Adj List of a Graph:\n";
    for(int i=0;i<v;i++){
        cout<<i<<" --> ";
        for(int j=0;j<g[i].size();j++){
            cout<<"{"<<g[i][j].first<<","<<g[i][j].second<<"}";
        }
        cout<<"\n";
    }


    return 0;
}

/*
5 6
0 1 2
1 2 3
0 3 6
1 3 8
1 4 5
2 4 7
*/