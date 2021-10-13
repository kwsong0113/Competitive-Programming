#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n, dp[1000001];

int main(){
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = i - 1; j >= i - 6; --j){
            if (j < 0) break;
            dp[i] = (dp[i] + dp[j]) % M;
        }
    }
    cout << dp[n];
}