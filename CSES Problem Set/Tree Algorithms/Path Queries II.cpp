#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18, M = 18;
int n, q, opt, a, b, val[N], subtreeSize[N], depth[N], up[M][N], id[N], tp[N], tree[2 * N], cnt = 1;
vector<int> adj[N];

void update(int a, int b, int l = 1, int r = n, int k = 1){
    if (l == r){
        tree[k] = b; return;
    }
    int mid = (l + r) >> 1;
    if (a <= mid) update(a, b, l, mid, k << 1);
    else update(a, b, mid + 1, r, k << 1 | 1);
    tree[k] = max(tree[k << 1], tree[k << 1 | 1]);
}

int query(int a, int b, int l = 1, int r = n, int k = 1){
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return tree[k];
    int mid = (l + r) >> 1;
    return max(query(a, b, l, mid, k << 1), query(a, b, mid + 1, r, k << 1 | 1));
}

void dfs(int u, int parent){
    subtreeSize[u] = 1;
    for (int i = 1; i < M; ++i){
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for (int v: adj[u]){
        if (v == parent) continue;
        depth[v] = depth[up[0][v] = u] + 1;
        dfs(v, u);
        subtreeSize[u] += subtreeSize[v];
    }
}

void dfs_hld(int u, int parent, int top){
    id[u] = cnt++;
    tp[u] = top;
    update(id[u], val[u]);
    int maxV = -1, maxSubtreeSize = -1;
    for (int v: adj[u]){
        if (v == parent) continue;
        if (subtreeSize[v] > maxSubtreeSize){
            maxV = v; maxSubtreeSize = subtreeSize[v];
        }
    }
    if (maxSubtreeSize == -1) return;
    dfs_hld(maxV, u, top);
    for (int v: adj[u]){
        if (v == parent || v == maxV) continue;
        dfs_hld(v, u, v);
    }
}

int jump(int x, int k){
    for (int i = 0; i < M; ++i){
        if (k & (1 << i)) x = up[i][x];
    }
    return x;
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    a = jump(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = M; i >= 0; --i){
        int aT = up[i][a], bT = up[i][b];
        if (aT != bT) a = aT, b = bT;
    }
    return up[0][a];
}

int path(int a, int b){
    int maxVal = 0;
    while (a != b){
        if (tp[a] == a){
            maxVal = max(maxVal, val[a]);
            a = up[0][a];
        } else if (depth[tp[a]] > depth[b]){
            maxVal = max(maxVal, query(id[tp[a]], id[a]));
            a = up[0][tp[a]];
        } else {
            maxVal = max(maxVal, query(id[b] + 1, id[a]));
            break;
        }
    }
    return maxVal;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> val[i];
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    up[0][1] = 1; dfs(1, 1);
    dfs_hld(1, 1, 1);
    while (q--){
        cin >> opt >> a >> b;
        if (opt == 1){
            val[a] = b;
            update(id[a], val[a]);
        } else {
            int c = lca(a, b);
            cout << max(max(path(a, c), path(b, c)), val[c]) << " ";
        }
    }
}