/*
Disjoint Set Union
(By rank and path compression)

To check weather two components lie in a same component or not

r[1000]=Stores rank

If rank[a]>rank[b] --> We have Point towards bigger rank --> par[b]=a

*/



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int r[1000];
int par[1000];


int findPar(int n){
    if(n==par[n])
        return n;
    return par[n]=findPar(par[n]);
}

void unionn(int u,int v){
    u=findPar(u);
    v=findPar(v);

    if(r[u]<r[v]){
        par[u]=v;
    }
    else if(r[u]>r[v]){
        par[v]=u;
    }
    else{
        par[v]=u;
        r[u]++;
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
        // g[y].push_back(x);
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

    memset(r,0,sizeof(r));
    
    unionn(0,1);
    unionn(1,2);
    unionn(3,4);
    unionn(5,6);
    unionn(4,5);
    unionn(2,6);

    for(int i=0;i<7;i++)
        cout<<i<<" : "<<par[i]<<"\n";

    return 0;
}

/*
7 7
0 0
1 1
2 2
3 3
4 4
5 5
6 6
*/
