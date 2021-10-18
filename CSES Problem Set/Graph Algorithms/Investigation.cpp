#include <bits/stdc++.h>
using namespace std;
const int N = 100001, M = 1e9 + 7;
const long long INF = 1e16;
int n, m, a, b, c;
long long dist[4][N];
vector<pair<int, int>> adj[N];
bool processed[N];
priority_queue<pair<long long, int>> q;

void dijkstra(){
    for (int i = 2; i <= n; ++i) dist[0][i] = INF;
    q.push({0, 1}); dist[1][1] = 1;
    while (!q.empty()){
        int u = q.top().second; q.pop();
        if (processed[u]) continue;
        processed[u] = true;
        for (auto [v, w]: adj[u]){
            long long newDist = dist[0][u] + w;
            if (dist[0][v] > newDist){
                dist[0][v] = newDist; dist[1][v] = dist[1][u]; dist[2][v] = dist[2][u] + 1; dist[3][v] = dist[3][u] + 1;
                q.push({-dist[0][v], v});
            }
            else if (dist[0][v] == newDist){
                (dist[1][v] += dist[1][u]) %= M; dist[2][v] = min(dist[2][v], dist[2][u] + 1); dist[3][v] = max(dist[3][v], dist[3][u] + 1);
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
    }
    dijkstra();
    for (int i = 0; i < 4; ++i) cout << dist[i][n] << " ";
}