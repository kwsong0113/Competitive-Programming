#include <bits/stdc++.h>
using namespace std;
const int N = 270000;
int n, q, a, b, newN, x[N], tree[2 * N];

void update(int k, int x){
   k += newN - 1;
   tree[k] = x;
   for (k /= 2; k >= 1; k /= 2) {
       tree[k] = tree[2 * k] ^ tree[2 * k + 1];
   }
}

void query(int a, int b){
    int ans = 0;
    a += newN - 1; b += newN - 1;
    while (a <= b){
        if (a % 2 == 1) ans ^= tree[a++];
        if (b % 2 == 0) ans ^= tree[b--];
        a /= 2; b /= 2;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    newN = (1 << (int)ceil(log2(n)));
    for (int i = 1; i <= n; ++i) cin >> tree[i + newN - 1]; 
    for (int i = newN - 1; i >= 1; --i) tree[i] = tree[2 * i] ^ tree[2 * i + 1];
    
    while (q--){
        cin >> a >> b;
        query(a, b);
    }
    
}