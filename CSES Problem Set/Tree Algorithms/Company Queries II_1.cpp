#include<bits/stdc++.h>
using namespace std;
const int N = 200001, M = 18;
int n, q, e, a, b, logVal, depth[N], ancestor[M][N];
vector<int> adj[N];

void dfs(int u){
    for (int i = 1; i <= logVal; ++i){
        ancestor[i][u] = ancestor[i - 1][ancestor[i - 1][u]];
    }
    
    for (int v: adj[u]){
        if (v != ancestor[0][u]){
            ancestor[0][v] = u; depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

int jump(int x, int k){
    for (int i = 0; i <= logVal; ++i){
        if (k & (1 << i)) x = ancestor[i][x];
    }
    return x;
}

int LCA(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    a = jump(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = logVal; i >= 0; --i){
        int aT = ancestor[i][a], bT = ancestor[i][b];
        if (aT != bT) a = aT, b = bT;
    }
    return ancestor[0][a];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; ++i){
        cin >> e; adj[e].push_back(i);
    }
    logVal = floor(log2(n));
    ancestor[0][1] = 1;
    dfs(1);
    
    while(q--){
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}