#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
const long long INF = LLONG_MAX;
int n, m, a, b, c;
bool processed[N];
long long dist[N];
priority_queue<pair<long long, int>> q;
vector<pair<int, int>> adj[N];
 
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    q.push({0, 1}); dist[1] = 0;
    while (!q.empty()){
        pair<int, int> u = q.top(); q.pop();
        if (processed[u.second]) continue;
        processed[u.second] = true;
        for (auto v: adj[u.second]){
            if (processed[v.first]) continue;
            long long newDist = dist[u.second] + v.second;
            if (newDist < dist[v.first]){
                dist[v.first] = newDist; q.push({-newDist, v.first});
            }
        }
    }
    for (int i = 1; i <= n ; ++i) cout << dist[i] << " ";
}