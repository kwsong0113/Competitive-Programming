#include <bits/stdc++.h>
using namespace std;
const int N = 200001, M = 18;
int n, q, a, b, t[N], comp[N], depth[N], idx[N], num[N], tmp[N], succ[N][M];
vector<int> adj[N], child[N];
bool inCycle[N];

void dfs(int u){
    int v = u;
    while (!tmp[v]){
        tmp[v] = u;
        v = t[v];
    }
    while (tmp[v] == u){
        tmp[v] = u + n;
        inCycle[v] = true; idx[v] = num[comp[v]]++;
        v = t[v];
    }
}

void DFS(int u){
    for (int v: child[u]){
        if (!inCycle[v]){
            depth[v] = depth[u] + 1;
            DFS(v);
        }
    }
}

void gencomp(int u, int i){
    if (comp[u]) return;
    comp[u] = i;
    for (int v: adj[u]) gencomp(v, i);
}

int successor(int u, int k){
    int ans = u;
    for (int i = 0; i < M; ++i){
        if (k & (1 << i)) ans = succ[ans][i];
    }
    return ans;
}

void solve(){
    if (comp[a] != comp[b]){
        cout << "-1\n"; return;
    }
    if (inCycle[a]){
        if (inCycle[b]) cout << (idx[b] - idx[a] + num[comp[a]]) % num[comp[a]] << "\n";
        else cout << "-1\n";
    }
    else {
        if (inCycle[b]){
            int aRoot = successor(a, depth[a]);
            cout << ((idx[b] - idx[aRoot] + num[comp[a]]) % num[comp[a]] + depth[a]) << "\n";
        }
        else {
            if (depth[b] > depth[a]){
                cout << "-1\n"; return;
            }
            if (successor(a, depth[a] - depth[b]) == b) cout << depth[a] - depth[b] << "\n";
            else cout << "-1\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> t[i];
        child[t[i]].push_back(i);
        adj[i].push_back(t[i]); adj[t[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) gencomp(i, i);
    for (int i = 1; i <= n; ++i) dfs(i);
    for (int i = 1; i <= n; ++i){
        if (inCycle[i]) DFS(i);
    }
    for (int i = 0; i < M; ++i){
        for (int j = 1; j <= n; ++j){
            if (i == 0) succ[j][i] = t[j];
            else succ[j][i] = succ[succ[j][i - 1]][i - 1];
        }
    }
    while (q--){
        cin >> a >> b;
        solve();
    }
}
