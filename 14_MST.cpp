/*
Minimum Spanning Tree

Requirments:
    1. Weighted Graph

Conditions for MST:
    1. Tree
    2. All nodes should be present
    3. (N-1) edges          N=Number of vertices
    4. Total weight should be minimum


        0 -- `1 -- 1                    0 -- `1 -- 1
        |          |                    |
       `2         `4         ----->     `2          
        |          |                    |          
        2 -- `3 -- 3                    2 -- `3 -- 3


Algorithms to find MST:
1.Prims Algo
2. Kruskal Algo




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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}