#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
int n, q, t[N], opt, a, b, x;

struct node {
    long long sum;
    long long lazyAdd;
    long long lazySet;
} tree[N << 1];

#define lk k << 1
#define rk k << 1 | 1

void pushup(int k){
    tree[k].sum = tree[lk].sum + tree[rk].sum;
}

void pushdown(int k, int l, int mid, int r){
    if(tree[k].lazySet != 0){
        tree[lk].lazySet = tree[rk].lazySet = tree[k].lazySet;
        tree[lk].sum = (mid - l + 1) * tree[k].lazySet;
        tree[rk].sum = (r - mid) * tree[k].lazySet;
        tree[lk].lazyAdd = tree[rk].lazyAdd = 0;
        tree[k].lazySet = 0;
    }
    else if(tree[k].lazyAdd != 0){
        if (tree[lk].lazySet == 0) tree[lk].lazyAdd += tree[k].lazyAdd;
        else tree[lk].lazySet += tree[k].lazyAdd;
        if (tree[rk].lazySet == 0) tree[rk].lazyAdd += tree[k].lazyAdd;
        else tree[rk].lazySet += tree[k].lazyAdd;
        tree[lk].sum += (mid - l + 1) * tree[k].lazyAdd;
        tree[rk].sum += (r - mid) * tree[k].lazyAdd;
        tree[k].lazyAdd = 0;
    }
}

void build(int k = 1, int l = 1, int r = n){
    tree[k].lazyAdd = tree[k].lazySet = 0;
    if (l == r){
        tree[k].sum = t[l]; return;
    }
    int mid = (l + r) >> 1;
    build(lk, l, mid); build(rk, mid + 1, r);
    pushup(k);
}

void add(int a, int b, int val, int k = 1, int l = 1, int r = n){
    if (l > b || r < a) return;
    if (l >= a && r <= b){
        tree[k].sum += 1LL * (r - l + 1) * val;
        if (tree[k].lazySet == 0) tree[k].lazyAdd += val;
        else tree[k].lazySet += val;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(k, l, mid, r);
    add(a, b, val, lk, l, mid); add(a, b, val, rk, mid + 1, r);
    pushup(k);
}

void set_(int a, int b, int val, int k = 1, int l = 1, int r = n){
    if (l > b || r < a) return;
    if (l >= a && r <= b){
        tree[k].sum = 1LL * (r - l + 1) * val;
        tree[k].lazyAdd = 0; tree[k].lazySet = val;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(k, l, mid, r);
    set_(a, b, val, lk, l, mid); set_(a, b, val, rk, mid + 1, r);
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
        cin >> opt;
        if (opt == 1){
            cin >> a >> b >> x; add(a, b, x);
        }
        else if (opt == 2){
            cin >> a >> b >> x; set_(a, b, x);
        }
        else {
            cin >> a >> b; cout << query(a, b) << "\n";
        }
    }
}