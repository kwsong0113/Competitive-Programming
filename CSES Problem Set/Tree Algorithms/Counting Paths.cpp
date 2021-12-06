#include <bits/stdc++.h>
using namespace std;
const int N = 200001, M = 18;
int n, m, a, b, e, logVal, depth[N], up[M][N], cnt = 1, ord[N], subTree[N], bit[N];
vector<int> adj[N];

void dfs(int u){
    ord[u] = cnt++;
    subTree[u] = 1;
    for (int i = 1; i <= logVal; ++i){
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for (int v: adj[u]){
        if (v != up[0][u]){
            depth[v] = depth[up[0][v] = u] + 1;
            dfs(v);
            subTree[u] += subTree[v];
        }
    }
}

int jump(int x, int k){
    for (int i = 0; i <= logVal; ++i){
        if (k & (1 << i)){
            x = up[i][x];
        }
    }
    return x;
}

int LCA(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    a = jump(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = logVal; i >= 0; --i){
        int aT = up[i][a], bT = up[i][b];
        if (aT != bT) a = aT, b = bT;
    }
    return up[0][a];
}

void add(int k, int x){
    while (k <= n){
        bit[k] += x;
        k += k & -k;
    }
}

int sum(int k){
    int s = 0;
    while (k >= 1){
        s += bit[k];
        k -= k & -k;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    logVal = floor(log2(n));
    up[0][1] = 1; dfs(1);
    while (m--){
        cin >> a >> b;
        int lca = LCA(a, b);
        add(ord[a], 1); add(ord[b], 1); add(ord[lca], -1);
        if (lca > 1) add(ord[up[0][lca]], -1);
    }
    for (int i = 1; i <= n; ++i){
        cout << sum(ord[i] + subTree[i] - 1) - sum(ord[i] - 1) << "\n";
    }
}