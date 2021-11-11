#include <bits/stdc++.h>
using namespace std;
const int N = 270000;
int n, m, newN, tree[2 * N], r, ans;

int query(int a, int b){
    int maxVal = 0;
    a += newN - 1; b += newN - 1;
    while (a <= b){
        if (a % 2 == 1) maxVal = max(maxVal, tree[a++]);
        if (b % 2 == 0) maxVal = max(maxVal, tree[b--]);
        a /= 2; b /= 2;
    }
    return maxVal;
}

void update(int k, int x){
    k += newN - 1;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2){
        tree[k] = max(tree[2 * k], tree[2 * k + 1]);
    }
}

int search(int k){
    if (k >= newN) return k - newN + 1;
    if (tree[2 * k] >= r) return search(2 * k);
    return search(2 * k + 1);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    newN = 1 << (int)ceil(log2(n));
    for (int i = 1; i <= n; ++i) cin >> tree[i + newN - 1];
    for (int i = newN - 1; i >= 1; --i){
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    
    while (m--){
        cin >> r;
        if (tree[1] < r) ans = 0;
        else {
            ans = search(1);
            update(ans, -r);
        }
        cout << ans << " ";
    }
}