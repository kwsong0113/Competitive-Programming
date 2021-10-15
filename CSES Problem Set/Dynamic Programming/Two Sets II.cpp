#include <bits/stdc++.h>
using namespace std;
const int M = 2 * (1e9 + 7);
int n, dp[501][62626];

int main(){
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2){
        cout << 0; return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= n * (n + 1) / 4; ++j){
            if (j > i * (i + 1) / 2) break;
            dp[i][j] = dp[i - 1][j];
            if (j >= i) dp[i][j] = (1LL * dp[i][j] + dp[i - 1][j - i]) % M;
        }
    }
    cout << dp[n][n * (n + 1) / 4] / 2;
}