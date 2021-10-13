#include <bits/stdc++.h>
using namespace std;
int n, m, dp[5001][5001];
string x, y;

int main(){
    cin >> x >> y;
    n = x.size(); m = y.size();
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            if (i == 0 || j == 0) dp[i][j] = i + j;
            else {
                if (x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]) + 1;
                }
            }
        }
    }
    cout << dp[n][m];
}