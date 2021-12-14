#include <bits/stdc++.h>
using namespace std;
const int N = 200001, M = 1e9 + 7;
int t, n, m, l, r, x, orVal, pow2[N];

void init(){
    pow2[0] = 1;
    for (int i = 1; i <= N - 1; ++i){
        pow2[i] = 2 * pow2[i - 1] % M;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> t;
    while (t--){
        cin >> n >> m;
        orVal = 0;
        while (m--){
            cin >> l >> r >> x;
            orVal |= x;
        }
        cout << 1LL * pow2[n - 1] * orVal % M << "\n";
    }
}