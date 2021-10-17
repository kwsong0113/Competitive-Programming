#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b;
vector<int> comp, adj[N];
bool visited[N];

void dfs(int x){
    if (visited[x]) return;
    visited[x] = true;
    for (int y: adj[x]) dfs(y);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i){
        if (!visited[i]){
            dfs(i); comp.push_back(i);
        }
    }
    cout << comp.size() - 1 << "\n";
    for (int i = 0 ; i < comp.size() - 1; ++i){
        cout << comp[i] << " " << comp[i + 1] << "\n";
    }
}