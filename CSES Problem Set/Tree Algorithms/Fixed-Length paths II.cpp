#include <bits/stdc++.h>
using namespace std;
const int N = 200002;
int n, k1, k2, a, b, maxDepth, subtreeSize[N];
long long cnt[N];
long long numPaths;
vector<int> adj[N];
bool processed[N];
 
void add(int k, long long x){
    k++;
    while (k <= k2 + 1){
        cnt[k] += x;
        k += k & -k;
    }
}
 
long long sum(int k){
    long long s = 0;
    k++;
    while (k >= 1){
        s += cnt[k];
        k -= k & -k;
    }
    return s;
}
 
long long query(int a, int b){
    return sum(b) - sum(a - 1);
}
 
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
    if (depth > k2) return;
    maxDepth = max(maxDepth, depth);
    if (update) add(depth, 1);
    else numPaths += query(max(k1 - depth, 0), k2 - depth);
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
    for (int i = 1; i <= maxDepth; ++i) add(i, -query(i, i));
    for (int v: adj[c]) if (!processed[v]){
        centroidDecomp(v);
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    add(0, 1);
    centroidDecomp();
    cout << numPaths;
}