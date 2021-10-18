#include <bits/stdc++.h>
using namespace std;
const int N = 100001, M = 1e9 + 7;
int n, m, a, b, num[N];
vector<int> adj[N];
bool visited[N];

void dfs(int u){
    if (visited[u]) return;
    visited[u] = true;
    for (int v: adj[u]){
        dfs(v);
        (num[u] += num[v]) %= M;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    num[n] = 1;
    dfs(1);
    cout << num[1];
}