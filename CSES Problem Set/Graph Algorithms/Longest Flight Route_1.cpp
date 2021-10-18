#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b, processed[N], parent[N], dp[N];
vector<int> adj1[N], adj2[N], nodes;

void dfs(int u){
    processed[u] = 1;
    for (int v: adj1[u]){
        if (processed[v] > 0) continue;
        dfs(v);
    }
    processed[u] = 2;
    nodes.push_back(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    dfs(1);
    if (processed[n]){
        reverse(nodes.begin(), nodes.end());
        for (int i = 1; i <= n; ++i) dp[i] = -1;
        dp[1] = 0; parent[1] = 1;
        for (int u: nodes){
            for (int v: adj2[u]){
                if (dp[u] < dp[v] + 1){
                    dp[u] = dp[v] + 1;
                    parent[u] = v;
                }
            }
        }
        int u = n;
        vector<int> path = {u};
        while (u != parent[u]){
            u = parent[u];
            path.push_back(u);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int x: path) cout << x << " ";
    }
    else {
        cout << "IMPOSSIBLE";
    }
}