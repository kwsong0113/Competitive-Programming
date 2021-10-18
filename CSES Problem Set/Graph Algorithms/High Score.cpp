#include <bits/stdc++.h>
using namespace std;
const int N = 2501;
typedef array<int, 3> triple;
const long long INF = -1e13;
int n, m, a, b, x, v, w;
long long dist[N];
vector<triple> edges;
vector<pair<int, int>> adj[2][N];
bool update, visited[2][N];
set<int> nodes;

void dfs(int u, int opt){
    if (visited[opt][u]) return;
    visited[opt][u] = true;
    for (auto e: adj[opt][u]){
        dfs(e.first, opt);
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b >> x;
        adj[0][a].push_back({b, x}); adj[1][b].push_back({a, x});
    }
    dfs(1, 0);
    dfs(n, 1);
    for (int i = 1; i <= n; ++i){
        if (visited[0][i] && visited[1][i]) nodes.insert(i);
    }
    for (int u: nodes){
        for (auto e: adj[0][u]){
            v = e.first, w = e.second;
            if (nodes.count(v)){
                edges.push_back(triple{u, v, w});
            }
        }
    }
    for (int i = 2; i <= n; ++i) dist[i] = INF;
    int i = 1;
    for (i = 1; i <= n; ++i){
        update = false;
        for (auto e: edges){
            if (dist[e[1]] < dist[e[0]] + e[2]){
                dist[e[1]] = dist[e[0]] + e[2];
                update = true;
            }
        }
        if (!update) break;
    }
    if (i > n) cout << "-1";
    else cout << dist[n];
}