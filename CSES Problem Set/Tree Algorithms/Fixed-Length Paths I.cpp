#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, k, a, b, maxDepth, subtreeSize[N], cnt[N]{1};
long long numPaths;
vector<int> adj[N];
bool processed[N];

int calcSubtreeSize(int u, int parent = 0){
    subtreeSize[u] = 1;
    for (int v: adj[u]) if (!processed[v] && v != parent){
        subtreeSize[u] += calcSubtreeSize(v, u);
    }
    return subtreeSize[u];
}

int centroid(int threshold, int u, int parent = 0){
    for (int v: adj[u]){
        if(!processed[v] && v != parent && subtreeSize[v] > threshold)
            return centroid(threshold, v, u);
    }
    return u;
}

void countPaths(int u, int parent, bool update, int depth = 1){
    if (depth > k) return;
    maxDepth = max(maxDepth, depth);
    if (update) cnt[depth]++;
    else numPaths += cnt[k - depth];
    for (int v: adj[u]) if (!processed[v] && v != parent){
        countPaths(v, u, update, depth + 1);
    }
}

void centroidDecomp(int u = 1){
    int c = centroid(calcSubtreeSize(u) / 2, u);
    processed[c] = true;
    maxDepth = 0;
    for (int v: adj[c]) if (!processed[v]){
        countPaths(v, c, false);
        countPaths(v, c, true);
    }
    fill(cnt + 1, cnt + maxDepth + 1, 0);
    for (int v: adj[c]) if (!processed[v]){
        centroidDecomp(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    centroidDecomp();
    cout << numPaths;
}