#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
int n, q, opt, a, b, x[N];

struct node {
    long long sum, pref;
    node(long long sum, long long pref) : sum(sum), pref(pref) {}
    node(long long x = 0) : sum(x), pref(max(0LL, x)) {}
    friend node operator+(const node&a, const node& b){
        return {a.sum + b.sum, max(a.pref, a.sum + b.pref)};
    }
} T[N << 1];

void build(int left = 1, int right = n, int k = 1){
    if (left == right){
        T[k] = node(x[left]); return;
    }
    int mid = (left + right) / 2;
    build(left, mid, 2 * k); build(mid + 1, right, 2 * k + 1);
    T[k] = T[2 * k] + T[2 * k + 1];
}

void update(int idx, int u, int left = 1, int right = n, int k = 1){
    if (left == right){
        T[k] = node(u); return;
    }
    int mid = (left + right) / 2;
    if (idx <= mid) update(idx, u, left, mid, 2 * k);
    else update(idx, u, mid + 1, right, 2 * k + 1);
    T[k] = T[2 * k] + T[2 * k + 1];
}

node query(int L, int R, int left = 1, int right = n, int k = 1){
    if (left > R || right < L) return node();
    if (left >= L && right <= R) return T[k];
    int mid = (left + right) / 2;
    node q1 = query(L, R, left, mid, 2 * k);
    node q2 = query(L, R, mid + 1, right, 2 * k + 1);
    return q1 + q2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    build();
    while (q--){
        cin >> opt >> a >> b;
        if (opt == 1) update(a, b);
        else cout << query(a, b).pref << "\n";
    }
}