#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
int n, q, newN, p, opt, k, x, tree[2][2 * N];

void update(int k, int x){
    tree[0][k + newN - 1] = x + k;
    tree[1][k + newN - 1] = x - k;
    k += newN - 1;
    for (k /= 2; k >= 1; k /= 2){
        tree[0][k] = min(tree[0][2 * k], tree[0][2 * k + 1]);
        tree[1][k] = min(tree[1][2 * k], tree[1][2 * k + 1]);
    }
}

int query(int opt, int a, int b){
    int minVal = INT_MAX;
    a += newN - 1; b += newN - 1;
    while (a <= b){
        if (a % 2 == 1) minVal = min(minVal, tree[opt][a++]);
        if (b % 2 == 0) minVal = min(minVal, tree[opt][b--]);
        a /= 2; b /= 2;
    }
    return minVal;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    newN = 1 << (int)ceil(log2(n));
    for (int i = 1; i <= n; ++i){
        cin >> p;
        tree[0][i + newN - 1] = p + i;
        tree[1][i + newN - 1] = p - i;
    }
    for (int i = newN - 1; i >= 1; --i){
        tree[0][i] = min(tree[0][2 * i], tree[0][2 * i + 1]);
        tree[1][i] = min(tree[1][2 * i], tree[1][2 * i + 1]);
    }
    while (q--){
        cin >> opt;
        if (opt == 1){
            cin >> k >> x;
            update(k, x);
        }
        else {
            cin >> k;
            int minVal = k + query(1, 1, k);
            if (k < n) minVal = min(minVal, query(0, k + 1, n) - k);
            cout << minVal << "\n";
        }
    }
}