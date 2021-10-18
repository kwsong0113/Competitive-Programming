#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b, dist[N], nextCity[N];
bool visited[N];
vector<int> adj[N];

void dfs(int u){
    if (visited[u]) return;
    visited[u] = true;
    for (int v: adj[u]){
        dfs(v);
        if (dist[v] >= 0 && dist[u] < dist[v] + 1){
            nextCity[u] = v;
            dist[u] = dist[v] + 1;
        }
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
    for (int i = 1; i <= n; ++i) dist[i] = -1;
    dist[n] = 0;
    dfs(1);
    if (dist[1] > 0){
        cout << dist[1] + 1 << "\n";
        int u = 1;
        cout << 1 << " ";
        while (u != n){
            u = nextCity[u];
            cout << u << " ";
        }
    }
    else cout << "IMPOSSIBLE";
}