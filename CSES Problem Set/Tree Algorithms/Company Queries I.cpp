#include <bits/stdc++.h>
using namespace std;
const int N = 200001, M = 18;
int n, q, x, k, logVal, boss[N], bossData[M][N];

int query(int x, int k){
    for (int i = 0; i <= logVal; ++i){
        if (k & (1 << i)){
            x = bossData[i][x];
        }
    }
    return x > 0 ? x : -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; ++i) cin >> boss[i];
    for (int i = 1; i <= n; ++i) bossData[0][i] = boss[i];
    logVal = (int)floor(log2(n));
    for (int i = 1; i <= logVal; ++i){
        for (int j = 1; j <= n; ++j){
            bossData[i][j] = bossData[i - 1][bossData[i - 1][j]];
        }
    }
    while (q--){
        cin >> x >> k;
        cout << query(x, k) << "\n";
    }
}