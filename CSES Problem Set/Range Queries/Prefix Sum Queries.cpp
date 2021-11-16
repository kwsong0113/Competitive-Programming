#include <bits/stdc++.h>
using namespace std;
const int N = 270000;
int n, q, a, b, newN;
long long tree[2][N];

void update(int k, int u){
    k += newN - 1;
    tree[k] = u;
    for (k /= 2; k >= 1; k /= 2){
        tree[0][k] = tree[0][2 * k] + tree[0][2 * k + 1];
        tree[1][k] = max(tree[1][2 * k], tree[0][2 * k] + tree[1][2 * k + 1]);
    }
}

long long query(int a, int b){
    long long maxVal = LLONG_MIN;
    a += newN - 1; b += newN - 1;
    while (a <= b){
        if (a % 2 == 1){
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    newN = 1 << (int)ceil(log2(n));
    for (int i = 1; i <= n; ++i){
        cin >> tree[0][i + newN - 1];
        tree[1][i + newN - 1] = tree[0][i + newN - 1];
    }
    for (int i = newN - 1; i >= 1; --i){
        tree[0][i] = tree[0][2 * i] + tree[0][2 * i + 1];
        tree[1][i] = max(tree[1][2 * i], tree[0][2 * i] + tree[1][2 * i + 1]);
    }
    
    while (q--){
        cin >> opt >> a >>  b;
        if (opt == 1) update(a, b);
        else cout << query(a, b) << "\n";
    }
}