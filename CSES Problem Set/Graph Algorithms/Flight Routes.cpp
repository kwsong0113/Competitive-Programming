#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, k, a, b, c, visited[N];
vector<pair<int, int>> adj[N];
priority_queue<pair<long long, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    q.push({0, 1});
    while (!q.empty() && visited[n] < k){
        long long d = q.top().first; int u = q.top().second; q.pop(); visited[u]++;
        if (u == n) cout << -d << " ";
        if (visited[u] <= k){
            for (auto [v, w]: adj[u]){
                q.push({d - w, v});
            }
        }
    }
}