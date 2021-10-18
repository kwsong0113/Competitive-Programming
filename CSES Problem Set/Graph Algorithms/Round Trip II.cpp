#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b, processed[N], parent[N];
vector<int> adj[N];
bool found = false;

void dfs(int u){
    if (found) return;
    processed[u] = 1;
    for (int v: adj[u]){
        if (found) return;
        if (processed[v] == 2) continue;
        else if (processed[v] == 1){
            vector<int> path = {v, u};
            while (u != v){
                u = parent[u];
                path.push_back(u);
            }
            reverse(path.begin(), path.end());
            cout << path.size() << "\n";
            for (int x: path) cout << x << " ";
            found = true;
            return;
        }
        parent[v] = u;
        dfs(v);
    }
    processed[u] = 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i){
        if (found) break;
        if (!processed[i]){
            parent[i] = i; dfs(i);
        }
    }
    if (!found){
        cout << "IMPOSSIBLE";
    }
}