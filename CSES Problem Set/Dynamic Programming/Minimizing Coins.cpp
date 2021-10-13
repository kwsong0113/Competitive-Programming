#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX / 2;
int n, x, c[101], dp[1000001];

int main(){
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= x; ++i){
        dp[i] = INF;
        for (int j = 1; j <= n; ++j){
            if (i - c[j] >= 0) dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    cout << (dp[x] >= INF ? -1 : dp[x]);
}