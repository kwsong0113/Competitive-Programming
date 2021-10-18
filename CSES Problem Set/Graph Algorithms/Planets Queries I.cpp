#include <bits/stdc++.h>
using namespace std;
const int N = 200001, M = 30;
int n, q, x, k, t[N], succ[N][M];

int successor(int x, int k){
    int ans = x;
    for (int i = 0; i < M; ++i){
        if (k & (1 << i)){
            ans = succ[ans][i];
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 0; i < M; ++i){
        for (int j = 1; j <= n; ++j){
            if (i == 0) succ[j][i] = t[j];
            else {
                succ[j][i] = succ[succ[j][i - 1]][i - 1];
            }
        }
    }
    while (q--){
        cin >> x >> k;
        cout << successor(x, k) << "\n";
    }
}