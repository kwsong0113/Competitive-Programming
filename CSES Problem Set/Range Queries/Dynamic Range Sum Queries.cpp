#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, q, opt, a, b, x[N];
long long sum[N], tree[N];

long long sumVal(int k){
    long long s = 0;
    while (k >= 1){
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

void update(int k, int u){
    int delta = u - x[k];
    x[k] = u;
    while (k <= n){
        tree[k] += delta;
        k += k & -k;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> x[i];
        sum[i] = sum[i - 1] + x[i];
    }
    for (int i = 1; i <= n; ++i){
        tree[i] = sum[i] - sum[i - (i & -i)];
    }
    
    while (q--){
        cin >> opt >> a >> b;
        if (opt == 1) update(a, b);
        else cout << (sumVal(b) - sumVal(a - 1)) << "\n";
    }
}