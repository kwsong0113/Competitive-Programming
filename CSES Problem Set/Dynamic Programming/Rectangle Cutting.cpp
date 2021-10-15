#include <bits/stdc++.h>
using namespace std;
const int INF = 250001;
int a, b, dp[501][501];

int main(){
    cin >> a >> b;
    if (a < b) swap(a, b);
    for (int i = 1; i <= a; ++i){
        for (int j = 1; j <= i - 1; ++j){
            dp[i][j] = INF;
            for (int k = 1; k <= i / 2; ++k){
                dp[i][j] = min(dp[i][j], 1 + dp[max(k, j)][min(k, j)] + dp[max(i - k, j)][min(i - k, j)]);
            }
            for (int l = 1; l <= j / 2; ++l){
                dp[i][j] = min(dp[i][j], 1 + dp[i][l] + dp[i][j - l]);
            }
        }
    }
    cout << dp[a][b];
}