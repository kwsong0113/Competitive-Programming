#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n, dp[1001][1001];
char grid[1001][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> (grid[i] + 1);
    }
    dp[1][1] = (grid[1][1] == '.');
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (grid[i][j] == '*') continue;
            if (i > 1) dp[i][j] += dp[i - 1][j];
            if (j > 1) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= M;
        }
    }
    cout << dp[n][n];
}