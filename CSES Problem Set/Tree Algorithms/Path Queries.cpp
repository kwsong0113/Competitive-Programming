#include <bits/stdc++.h>
using namespace std;
const int N = 270000;
int n, q, a, b, opt, cnt = 1, val[N], st[N], en[N];
long long tree[2 * N];
vector<int> adj[N];

void dfs(int u, int prev){
    st[u] = cnt++;
    for (int v: adj[u]){
        if (v != prev){
            dfs(v, u);
        }
    }
    en[u] = cnt - 1;
}

void update(int a, int b, int l = 1, int r = n, int k = 1){
    if (l == r){
        tree[k] += b; return;
    }
    int mid = (l + r) >> 1;
    if (a <= mid) update(a, b, l, mid, k << 1);
    else update(a, b, mid + 1, r, k << 1 | 1);
    tree[k] = tree[k << 1] + tree[k << 1 | 1];
}

void add(int u, int x){
    update(st[u], x);
    if (en[u] < n) update(en[u] + 1, -x);
}

long long query(int a, int b, int l = 1, int r = n, int k = 1){
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return tree[k];
    int mid = (l + r) >> 1;
    return query(a, b, l, mid, k << 1) + query(a, b, mid + 1, r, k << 1 | 1);
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
    dfs(1, 0);
    for (int i = 1; i <= n; ++i){
        add(i, val[i]);
    }
    while (q--){
        cin >> opt;
        if (opt == 1){
            cin >> a >> b;
            add(a, b - val[a]); val[a] = b;
        } else {
            cin >> a;
            cout << query(1, st[a]) << "\n";
        }
    }
}