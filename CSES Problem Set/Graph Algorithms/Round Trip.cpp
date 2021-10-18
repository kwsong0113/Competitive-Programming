#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b, parent[N];
vector<int> adj[N];
bool cycle = false;
 
void dfs(int u){
    if (cycle) return;
    for (int v: adj[u]){
        if (cycle) return;
        if (parent[v]){
            if (parent[u] != v){
                vector<int> path = {u}; int x = u;
                while(x != v){
                    x = parent[x];
                    path.push_back(x);
                }
                path.push_back(u);
                cout << path.size() << "\n";
                for (int y: path) cout << y << " ";
                cycle = true; return;
            }
        }
        else {
            parent[v] = u; dfs(v);
        }
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i){
        if (!parent[i]){
            parent[i] = i; dfs(i);
        }
        if (cycle) return 0;
    }
    cout << "IMPOSSIBLE";
}