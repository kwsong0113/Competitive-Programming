#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, a, b, treeSize[N];
long long sum[N];
vector<int> adj[N];

void dfsDown(int u, int e){
    treeSize[u] = 1;
    for (int v: adj[u]){
        if (v == e) continue;
        dfsDown(v, u);
        treeSize[u] += treeSize[v];
        sum[u] += sum[v] + treeSize[v];
    }
}

void dfsUp(int u, int e){
    for (int v: adj[u]){
        if (v == e) continue;
        sum[v] = sum[u] + n - 2 * treeSize[v];
        dfsUp(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfsDown(1, 0); dfsUp(1, 0);
    for (int i = 1; i <= n; ++i) cout << sum[i] << " ";
}