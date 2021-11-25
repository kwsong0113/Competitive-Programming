#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, boss, treeSize[N];
vector<int> adj[N];

void dfs(int u, int e){
    treeSize[u] = 1;
    for (auto v: adj[u]){
        if (v == e) continue;
        dfs(v, u);
        treeSize[u] += treeSize[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; ++i){
        cin >> boss;
        adj[boss].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << (treeSize[i] - 1) << " ";
}