#include <bits/stdc++.h>
using namespace std;
int n, x, h[1001], s[1001], dp[1001][100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= x; ++j){
            dp[i][j] = dp[i - 1][j];
            int rem = j - h[i];
            if (rem >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][rem] + s[i]);
        }
    }
    cout << dp[n][x];
}