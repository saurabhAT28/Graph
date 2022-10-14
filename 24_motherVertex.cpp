/*
Find Mother Vertex

Mother Vertex:
It is a vertex such that all other vertices in a graph reached by a path from vertex


Cases:
1. Disconnected Graph: No mother vertes
2. Undirected Connected Graph: All vertices are mother vertex
3. Directed Connected Graph: May be

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int src,vector<int>&vis,vector<int>g[]){
    vis[src]=1;
    for(auto x:g[src]){
        if(!vis[x])
            dfs(x,vis,g);
    }
}

void findMotherVertex(int v, vector<int>g[])
{
	vector<int>vis(v,0);
	    
	int mother;
	for(int i=0;i<v;i++){
	    if(vis[i]==0){
	        dfs(0,vis,g);
	        mother=i;
            // cout<<mother<<endl;
	    }
	}
	    
	fill(vis.begin(),vis.end(),0);
	    
	dfs(mother,vis,g);
	
    bool flag=true;
	for(int i=0;i<v;i++){
        if(vis[i]==0){
            flag=false;
            break;
        }
    }

    if(flag)
        cout<<"Mother Vertex: "<<mother<<endl;
    else
        cout<<"No mother vertex\n";

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

    findMotherVertex(v,g);

    return 0;
}


/*
5 5
0 3
0 2
1 0
2 1
3 4


*/