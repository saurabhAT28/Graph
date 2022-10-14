/*
Graph Coloring Problem

Conditions:
    1. Colour all Nodes
    2. Use minimum number of colors (Chromatic Number)
    3. No 2 adjacent should have same color

res[v]=Stored color of all nodes
available[v]=Available color 
True=Not available to choose 
False=available to Choose

TC=O(v*v)
SC=O(v)

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void noOfColor(int v,vector<int>g[]){
    vector<int>res(v,-1);
    res[0]=0;
    vector<int>available(v,false);

    int cn=0;
    for(int i=1;i<v;i++){
        for(auto x:g[i]){
            if(res[x]!=-1)
                available[res[x]]=true;
        }

        int cr;
        for(cr=0;cr<v;cr++){
            if(available[cr]==false)
                break;
        }

        res[i]=cr;
        cn=max(cn,cr+1);

        for(auto x:g[i]){
            if(res[x]!=-1)
                available[res[x]]=false;
        }
    }

    cout<<"No. of colors: "<<cn<<endl;
    cout<<"Nodes and Color:\n";
    for(int i=0;i<v;i++){
        cout<<i<<" --> "<<res[i]<<"\n";
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
    noOfColor(v,g);

    return 0;
}

/*
5 6
0 1
1 3
2 3
0 2
2 4
1 4
*/