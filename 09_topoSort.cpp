/*
Topological Sort
Using BFS

Requirment
1. Only in Directed Graph
2. Acyclic Graph

Indegree: No. of edes coming on a node

Print nodes with 0 indegree and remove edges of that node

0<=value of node
 
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printVector(vector<int>v){
    int n=v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
}

vector<int> topoSort(int v,vector<int>g[]){
    vector<int>in(v,0);
    queue<int>q;

    for(int i=0;i<v;i++){
        for(int j=0;j<g[i].size();j++){
            in[g[i][j]]++;
        }
    }

    vector<int>ans;

    for(int i=0;i<v;i++){
        if(in[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int i=q.front();
        q.pop();
        ans.push_back(i);
        for(int j=0;j<g[i].size();j++){
            in[g[i][j]]--;
            if(in[g[i][j]]==0)
                q.push(g[i][j]);
        }
    }

    return ans;
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

    vector<int>ans=topoSort(v,g);
    printVector(ans);
    return 0;
}

/*
4 3
1 0
2 0
3 0

*/