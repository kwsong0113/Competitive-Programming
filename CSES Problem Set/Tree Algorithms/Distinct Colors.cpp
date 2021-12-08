#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, a, b, c[N], ans[N];
set<int> colors[N];
vector<int> adj[N];

void dfs(int u, int parent){
    colors[u].insert(c[u]);
    for (int v: adj[u]){
        if (v == parent) continue;
        dfs(v, u);
        if (colors[u].size() < colors[v].size()) swap(colors[u], colors[v]);
        colors[u].insert(colors[v].begin(), colors[v].end());
    }
    ans[u] = colors[u].size();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}