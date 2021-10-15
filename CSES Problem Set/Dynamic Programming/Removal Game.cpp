#include <bits/stdc++.h>
using namespace std;
int n, x[5001];
pair<long long, long long> dp[5001][5001], temp1, temp2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = n; i >= 1; --i){
        for (int j = i; j <= n; ++j){
            if (i == j) dp[i][j] = {x[i], 0};
            else {
                temp1 = dp[i + 1][j]; temp2 = dp[i][j - 1];
                temp1.second += x[i]; temp2.second += x[j];
                if (temp1.second > temp2.second) dp[i][j] = {temp1.second, temp1.first};
                else dp[i][j] = {temp2.second, temp2.first};
            }
        }
    }
    cout << dp[1][n].first;
}