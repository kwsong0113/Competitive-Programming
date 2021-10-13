#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n, m, ans, x[100001], dp[100001][101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    if (x[n]) dp[n][x[n]] = 1;
    else {
        for (int i = 1; i <= m; ++i) dp[n][i] = 1;
    }
    for (int i = n - 1; i >= 1; --i){
        if (x[i]){
            dp[i][x[i]] += dp[i + 1][x[i]];
            if (x[i] > 1) (dp[i][x[i]] += dp[i + 1][x[i] - 1]) %= M;
            if (x[i] < m) (dp[i][x[i]] += dp[i + 1][x[i] + 1]) %= M;
        }
        else {
            for (int j = 1; j <= m; ++j){
            dp[i][j] += dp[i + 1][j];
            if (j > 1) (dp[i][j] += dp[i + 1][j - 1]) %= M;
            if (j < m) (dp[i][j] += dp[i + 1][j + 1]) %= M;
            }
        }
    }
    for (int i = 1; i <= m; ++i) (ans += dp[1][i]) %= M;
    cout << ans;
}