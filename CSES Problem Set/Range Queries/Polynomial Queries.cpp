#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
int n, q, opt, a, b, t[N];
struct node {
    long long sum;
    long long z1;
    long long z0;
} tree[N << 1];

# define lk k << 1
# define rk k << 1 | 1

void pushup(int k){
    tree[k].sum = tree[lk].sum + tree[rk].sum;
}

void pushdown(int k, int l, int mid, int r){
    tree[lk].z1 += tree[k].z1; tree[lk].z0 += tree[k].z0;
    tree[rk].z1 += tree[k].z1; tree[rk].z0 += tree[k].z0 + tree[k].z1 * (mid + 1 - l);
    tree[lk].sum += tree[k].z1 * (mid - l) * (mid - l + 1) / 2 + tree[k].z0 * (mid - l + 1);
    tree[rk].sum += tree[k].z1 * (r - mid - 1) * (r - mid) / 2 + (tree[k].z0 + tree[k].z1 * (mid + 1 - l)) * (r - mid);
    tree[k].z1 = tree[k].z0 = 0;
}

void build(int k = 1, int l = 1, int r = n){
    tree[k].z1 = tree[k].z0 = 0;
    if (l == r){
        tree[k].sum = t[l]; return;
    }
    int mid = (l + r) >> 1;
    build(lk, l, mid); build(rk, mid + 1, r);
    pushup(k);
}

void update(int a, int b, int k = 1, int l = 1, int r = n){
    if (l > b || r < a) return;
    if (l >= a && r <= b){
        tree[k].sum += 1LL * (r - l + 1) * (l + r - 2 * a + 2) / 2;
        tree[k].z1 += 1; tree[k].z0 += l - a + 1;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(k, l, mid, r);
    update(a, b, lk, l, mid); update(a, b, rk, mid + 1, r);
    pushup(k);
}

long long query(int a, int b, int k = 1, int l = 1, int r = n){
    if (l > b || r < a) return 0;
    if (l >= a && r <= b){
        return tree[k].sum;
    }
    int mid = (l + r) >> 1;
    pushdown(k, l, mid, r);
    return query(a, b, lk, l, mid) + query(a, b, rk, mid + 1, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    build();
    while (q--){
        cin >> opt >> a >> b;
        if (opt == 1) update(a, b);
        else cout << query(a, b) << "\n";
    }
}