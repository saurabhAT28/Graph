#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v,e;
    cin>>v>>e;

    int g[v+1][v+1];

    memset(g,0,sizeof(g));

    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        g[x][y]=1;
        g[y][x]=1;
    }

    for(int i=1;i<=v;i++){
        cout<<i<<" --> ";
        for(int j=1;j<=v;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}
