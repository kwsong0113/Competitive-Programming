#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b, visited[N];
vector<int> adj[N];
bool pos = true;

void dfs(int u){
    for (int v: adj[u]){
        if (!visited[v]){
            visited[v] = 3 - visited[u]; dfs(v);
        }
        else if (visited[v] == visited[u]){
            pos = false; return;
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
        if (!visited[i]){
            visited[i] = 1; dfs(i);
            if (!pos){
                cout << "IMPOSSIBLE"; return 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << visited[i] << " ";
}