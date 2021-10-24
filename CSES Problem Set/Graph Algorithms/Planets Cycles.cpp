#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, t[N], comp[N], inCycle[N], num[N], tmp[N], depth[N];
vector<int> adj[N], child[N];

void dfs(int u){
    int v = u;
    while (!tmp[v]){
        tmp[v] = u;
        v = t[v];
    }
    while (tmp[v] == u){
        tmp[v] = u + n;
        inCycle[v] = true; num[comp[v]]++;
        v = t[v];
    }
}

void DFS(int u){
    for (int v: child[u]){
        if (!inCycle[v]){
            depth[v] = depth[u] + 1;
            DFS(v);
        }
    }
}

void genComp(int u, int i){
    if (comp[u]) return;
    comp[u] = i;
    for (int v: adj[u]) genComp(v, i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> t[i];
        adj[i].push_back(t[i]); adj[t[i]].push_back(i);
        child[t[i]].push_back(i);
    }
    
    for (int i = 1; i <= n; ++i){
        genComp(i, i); dfs(i);
    }
    for (int i = 1; i <= n; ++i){
        if (inCycle[i]) DFS(i);
    }
    for (int i = 1; i <= n; ++i){
        cout << (num[comp[i]] + depth[i]) << " ";
    }
}