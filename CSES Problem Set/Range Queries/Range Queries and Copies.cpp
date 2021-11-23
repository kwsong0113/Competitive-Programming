#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, q, opt, k, a, b, cnt = 1, t[N];

struct node {
    long long val;
    node *l, *r;
    node(long long x) : val(x), l(nullptr), r(nullptr) {}
    node(node *ll, node *rr){
        l = ll, r = rr;
        val = 0;
        if (l) val += l -> val;
        if (r) val += r -> val;
    }
    node(node *cp) : val(cp -> val), l(cp -> l), r(cp -> r) {}
};

node* roots[N];

node* build(int l = 1, int r = n){
    if (l == r) return new node(t[l]);
    int mid = (l + r) >> 1;
    return new node(build(l, mid), build(mid + 1, r));
}

node* update(node *nd, int pos, int val, int l = 1, int r = n){
    if (l == r) return new node(val);
    int mid = (l + r) >> 1;
    if (pos <= mid) return new node(update(nd -> l, pos, val, l, mid), nd -> r);
    else return new node(nd -> l, update(nd -> r, pos, val, mid + 1, r));
}

long long query(node *nd, int a, int b, int l = 1, int r = n){
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return nd -> val;
    int mid = (l + r) >> 1;
    return query(nd -> l, a, b, l, mid) + query(nd -> r, a, b, mid + 1, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    roots[cnt++] = build();   
    while (q--){
        cin >> opt;
        if (opt == 1){
            cin >> k >> a >> b;
            roots[k] = update(roots[k], a, b);
        } else if (opt == 2){
            cin >> k >> a >> b;
            cout << query(roots[k], a, b) << "\n";
        } else {
            cin >> k;
            roots[cnt++] = new node(roots[k]);
        }
    }
}