#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
int n, m, a, b, c, q;
long long dist[501][501];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            dist[i][j] = (i == j ? 0 : INF);
        }
    }
    for (int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (long long)c);
        dist[b][a] = dist[a][b];
    }
    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j < n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dist[j][i] = dist[i][j];
            }
        }
    }
    
    while (q--){
        cin >> a >> b;
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << "\n";
    }
}