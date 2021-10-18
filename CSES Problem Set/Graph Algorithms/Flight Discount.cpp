#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
const long long INF = 1e15;
int n, m, a, b, c;
long long dist[N];
vector<pair<int, int>> adj[N];
bool processed[N];
priority_queue<pair<long long, int>> q;

void dijkstra(){
    for (int i = 2; i <= 2 * n; ++i) dist[i] = INF;
    q.push({0, 1});
    while (!q.empty()){
        int u = q.top().second; q.pop();
        if (processed[u]) continue;
        processed[u] = true;
        for (auto e: adj[u]){
            int v = e.first, w = e.second;
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[a].push_back({b + n, c / 2});
        adj[a + n].push_back({b + n, c});
    }
    dijkstra();
    cout << dist[2 * n];
}