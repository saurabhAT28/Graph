/*
Detect Cycle in Directed Graph Using DFS
Topo Sort
            1--->2
                 |
                 V
            4<---3

If cycle is present in directed graph then there is always one node with indegree is non zero.

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isCyclic(int v,vector<int>g[]){
    vector<int>in(v,0);
    queue<int>q;

    for(int i=0;i<v;i++){
        for(int j=0;j<g[i].size();j++){
            in[g[i][j]]++;
        }
    }

    int count=0;

    for(int i=0;i<v;i++){
        if(in[i]==0){
            q.push(i);
            count++;
        }
           
    }

    while(!q.empty()){
        int i=q.front();
        q.pop();

        for(int j=0;j<g[i].size();j++){
            in[g[i][j]]--;
            if(in[g[i][j]]==0){
                q.push(g[i][j]);
                count++;
            }       
        }
    }

    return count!=v;
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
*/