#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, a, b, subtreeSize[N];
vector<int> adj[N];

void dfs(int u, int parent){
    subtreeSize[u] = 1;
    for (int v: adj[u]){
        if (v == parent) continue;
        dfs(v, u);
        subtreeSize[u] += subtreeSize[v];
    }
}

int centroid(int u, int parent){
    int maxV = -1, maxSubtreeSize = -1;
    for (int v: adj[u]){
        if (v == parent) continue;
        if (subtreeSize[v] > maxSubtreeSize){
            maxV = v; maxSubtreeSize = subtreeSize[v];
        }
    }
    if (maxSubtreeSize <= n / 2) return u;
    return centroid(maxV, u);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << centroid(1, 0);
}