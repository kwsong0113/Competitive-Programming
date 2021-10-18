#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b, processed[N];
vector<int> adj[N], ans;
bool found;

void dfs(int u){
    if (found) return;
    processed[u] = 1;
    for (int v: adj[u]){
        if (found) return;
        if (processed[v] == 0) dfs(v);
        else if (processed[v] == 1){
            found = true; cout << "IMPOSSIBLE";
        }
    }
    processed[u] = 2;
    ans.push_back(u);
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
        if (!processed[i]) dfs(i);
    }
    if (!found){
        reverse(ans.begin(), ans.end());
        for (int x: ans) cout << x << " ";
    }
}