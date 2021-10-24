#include <bits/stdc++.h>
using namespace std;
const int N = 270000;
int n, q, opt, a, b, newN, x[N], tree[2 * N];

void update(int k, int u){
    k += newN - 1;
    tree[k] = u;
    for (k /= 2; k >= 1; k /= 2){
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);
    }
}

void query(int a, int b){
    int minVal = 1e9 + 1;
    a += newN - 1; b += newN - 1;
    while (a <= b){
        if (a % 2 == 1) minVal = min(minVal, tree[a++]);
        if (b % 2 == 0) minVal = min(minVal, tree[b--]);
        a /= 2; b /= 2;
    }
    cout << minVal << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    newN = (1 << (int)ceil(log2(n)));
    for (int i = 1; i <= n; ++i){
        cin >> x[i]; tree[i + newN - 1] = x[i];
    }
    for (int i = newN - 1; i >= 1; --i){
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
        
    while (q--){
        cin >> opt >> a >> b;
        if (opt == 1) update(a, b);
        else query(a, b);
    }
}