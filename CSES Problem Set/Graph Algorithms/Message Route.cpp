#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b, u;
int parent[N], dist[N];
vector<int> adj[N];
queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    q.push(1);
    parent[1] = 1;
    while (!q.empty()){
        u = q.front(); q.pop();
        for (int v: adj[u]){
            if (parent[v]) continue;
            parent[v] = u;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    if (parent[n]){
        cout << dist[n] + 1 << "\n";
        vector<int> path = {n};
        while (parent[n] != n){
            path.push_back(parent[n]);
            n = parent[n];
        }
        reverse(path.begin(), path.end());
        for (int v: path) cout << v << " ";
    }
    else {
        cout << "IMPOSSIBLE";
    }
}