#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
int n, m, k, y, x[N];
 
 
struct node {
    long long sum, pref, suff, subarr;
    node(long long sum, long long pref, long long suff, long long subarr): sum(sum), pref(pref), suff(suff), subarr(subarr) {}
    node(long long x = 0) : sum(x), pref(max(0LL, x)), suff(max(0LL, x)), subarr(max(0LL, x)) {}
    friend node operator+(const node&a, const node&b){
        return {a.sum + b.sum, max(a.pref, a.sum + b.pref), max(b.suff, a.suff + b.sum), max(max(a.subarr, b.subarr), a.suff + b.pref)};
    }
} T[N << 1];
 
 
void build(int l = 1, int r = n, int k = 1){
    if (l == r){
        T[k] = node(x[l]); return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, k << 1); build(mid + 1, r, k << 1 | 1);
    T[k] = T[k << 1] + T[k << 1 | 1];
}
 
void update(int a, int b, int l = 1, int r = n, int k = 1){
    if (l == r){
        T[k] = node(b); return;
    }
    int mid = (l + r) >> 1;
    if (a <= mid) update(a, b, l, mid, k << 1);
    else update(a, b, mid + 1, r, k << 1 | 1);
    T[k] = T[k << 1] + T[k << 1 | 1];
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    build();
    while (m--){
        cin >> k >> y;
        update(k, y);
        cout << T[1].subarr << "\n";
    }
}