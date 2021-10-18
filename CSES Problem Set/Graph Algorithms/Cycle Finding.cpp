#include <bits/stdc++.h>
using namespace std;
typedef array<int, 3> triple;
const int N = 2501;
const long long INF = 1e14;
int n, m, a, b, c, parent[N];
long long dist[N];
bool processed[N];
vector<pair<int, int>> adj[N];
vector<triple> edges;

void dfs(int u){
    if (processed[u]) return;
    processed[u] = true;
    for (auto e: adj[u]){
        int v = e.first, w = e.second;
        edges.push_back(triple{u, v, w});
        dfs(v);
    }
}

int bellmanFord(int u){
    for (int i = 1; i <= n; ++i){
        dist[i] = INF; parent[i] = 0;
    }
    dist[u] = 0; parent[u] = u;
    for (int i = 1; i <= n; ++i){
        for (auto e: edges){
            if (dist[e[0]] != INF && dist[e[1]] > dist[e[0]] + e[2]){
                dist[e[1]] = dist[e[0]] + e[2];
                parent[e[1]] = e[0];
                if (i == n) return e[1];
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    int v;
    for (int i = 1; i <= n; ++i){
        if (!processed[i]) {
            edges.clear();
            dfs(i);
            v = bellmanFord(i);
            if (v > 0) break;
        }
    }
    if (v == -1) cout << "NO";
    else {
        vector<int> ans;
        set<int> visited;
        while (!visited.count(v)){
            ans.push_back(v);
            visited.insert(v);
            v = parent[v];
        }
        ans.erase(ans.begin(), find(ans.begin(), ans.end(), v));
        ans.push_back(v);
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        for (int u: ans) cout << u << " ";
    }
}