/*
BFS
TC=O(V+E)
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

vector<int> bfs(int v,vector<int>g[]){
    queue<int>q;
    q.push(0);

    vector<int>ans;
    vector<int>vis(v+1);

    while(!q.empty()){
        int node=q.front();
        q.pop();

        ans.push_back(node);

        for(auto x:g[node]){
            if(!vis[x]){
                q.push(x);
                vis[x]=1;
            }
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

    // Directed
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

    vector<int>ans=bfs(v,g);
    printVector(ans);


    return 0;
}

/*
Directed graph
6 5
0 1
0 2
0 3
1 5
2 4
*/