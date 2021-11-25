#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, a, b, f[N], g[N];
vector<int> adj[N];

void dfs(int u, int e){
    bool b = false;
    for (int v: adj[u]){
        if (v == e) continue;
        dfs(v, u);
        g[u] += f[v];
        if (f[v] == g[v]) b = true;
    }
    f[u] = g[u] + b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << f[1];
}