/*
Prim's Algorithm (Efficient Approach)

By using min Heap

TC=O(V*logV)

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void primsAlgo(int v,vector<pair<int,int>>g[]){
    int parent[v];
    int key[v];
    int mstSet[v];

    for(int i=0;i<v;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

    minHeap.push({0,0});

    key[0]=0;
    parent[0]=-1;

    // For v-1 edges
    while(!minHeap.empty()){
        int u=minHeap.top().second;
        minHeap.pop();

        mstSet[u]=true;

        for(auto x:g[u]){
            int y=x.first;
            int wt=x.second;
            if(mstSet[y]==false && wt<key[y]){
                parent[y]=u;
                key[y]=wt;
                minHeap.push({key[y],y});
            }
        }
    }
    
    cout<<"MST:\n";
    for(int i=1;i<v;i++)
        cout<<parent[i]<<" --> "<<i<<" Wt: "<<key[i]<<"\n";
}


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
    cout<<"*********************\n";

    primsAlgo(v,g);

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