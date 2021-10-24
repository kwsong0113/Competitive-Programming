#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b;
vector<int> adj[2][N];
bool visited[2][N];

void dfs(int u, int opt){
    if (visited[opt][u]) return;
    visited[opt][u] = true;
    for (int v: adj[opt][u]) dfs(v, opt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        adj[0][a].push_back(b); adj[1][b].push_back(a);
    }
    dfs(1, 0); dfs(1, 1);
    for (int i = 1; i <= n; ++i){
        if (!visited[0][i]){
            cout << "NO\n" << 1 << " " << i;
            return 0;
        }
        if (!visited[1][i]){
            cout << "NO\n" << i << " " << 1;
            return 0;
        }
    }
    cout << "YES";
}