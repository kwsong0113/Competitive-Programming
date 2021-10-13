#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n, x, c, dp[101][1000001], coins[101];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> coins[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= x; ++j){
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i]) dp[i][j] += dp[i][j - coins[i]];
            dp[i][j] %= M;
        }
    }
    cout << dp[n][x];
}