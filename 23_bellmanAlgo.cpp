/*
Bellman Ford Algorithm
Directed graph
Check for the presence of negative cycle

Negative Cycle:
Overall sum of cycle is negative

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{
    int u,v,wt;

    node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

void printVector(vector<int>v){
    int n=v.size();
    cout<<"node --> distance\n";
    for(int i=0;i<n;i++){
        cout<<i<<" --> "<<v[i]<<"\n";
    }
}


void bellmanFord(int source,int N,vector<node>g){
    vector<int>dist(N,INT_MAX);
    dist[source]=0;

    for(int i=0;i<N-1;i++){
        for(auto it:g){
            if(dist[it.u]!=INT_MAX && dist[it.u]+it.wt<dist[it.v])
                dist[it.v]=dist[it.u]+it.wt;
        }
    }

    // Check Negative cycle is present or not
    bool flag=false;
    for(auto it:g){
        if(dist[it.u]+it.wt<dist[it.v]){
            flag=true;
            break;
        }
    }

    if(flag){
        cout<<"Negative cycle is present.";
    }
    else{
        cout<<"Negative cycle is NOT present.\n";
        printVector(dist);
    }

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,e,source;
    cin>>N>>e>>source;

    vector<node>g;

    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g.push_back(node(u,v,wt));
    }

    cout<<"Adj List of a Graph:\n";
    cout<<"u --> v --> Wt\n";
    for(int i=0;i<e;i++){
        cout<<g[i].u<<" --> "<<g[i].v<<" --> "<<g[i].wt<<"\n";
    }
    cout<<"*********************\n";

    bellmanFord(source,N,g);

    return 0;
}


/*
6 7 0
0 1 5
1 5 -3
1 2 -2
2 4 3
3 2 6
3 4 -2
5 3 1

*/