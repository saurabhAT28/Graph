/*
Kruskal's Algorithm for MST
(by using DSU)

Procedure:
    1. Stored the whole graph in a linear data structure
    2. Sort w.r.t. weight (w,a,b)
    3. Then make the union of u,v


*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int r[1000];
int par[1000];

struct node{
    int u,v,wt;

    node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};


void printMST(vector<node>mst){
    int n=mst.size();
    cout<<"MST:\n";
    cout<<"u --> v --> Wt\n";
    for(int i=0;i<n;i++){
        cout<<mst[i].u<<" --> "<<mst[i].v<<" --> "<<mst[i].wt<<"\n";
    }
    cout<<"*********************\n";
}

static bool compare(node a,node b){
    // Sort in ascending order wrt to weight
    return a.wt<b.wt;
}


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

void kruskal(int N,vector<node>g){
    memset(r,0,N);
    for(int i=0;i<N;i++)
        par[i]=i;

    int cost=0;
    vector<node>mst;

    for(auto it:g){
        if(findPar(it.v)!=findPar(it.u)){
            cost+=it.wt;
            mst.push_back(it);
            unionn(it.u,it.v);
        }
    }

    cout<<"Total cost: "<<cost<<"\n";
    printMST(mst);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,e;
    cin>>N>>e;

    vector<node>g;

    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g.push_back(node(u,v,wt));
    }

    cout<<"Graph before sorting:\n";
    cout<<"u --> v --> Wt\n";
    for(int i=0;i<e;i++){
        cout<<g[i].u<<" --> "<<g[i].v<<" --> "<<g[i].wt<<"\n";
    }
    cout<<"*********************\n";


    sort(g.begin(),g.end(),compare);

    cout<<"Graph AFTER sorting:\n";
    cout<<"u --> v --> Wt\n";
    for(int i=0;i<e;i++){
        cout<<g[i].u<<" --> "<<g[i].v<<" --> "<<g[i].wt<<"\n";
    }
    cout<<"*********************\n";

    
    kruskal(N,g);

    
    

    // for(int i=0;i<N;i++)
    //     cout<<i<<" : "<<par[i]<<"\n";

    return 0;
}

/*
6 9
0 1 2
0 4 4
0 3 1
4 3 9
1 3 3
1 2 3
2 3 5
1 5 7
2 5 8

*/