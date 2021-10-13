#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n, x, c, dp[1000001];
vector<int> coins;

int main(){
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> c; coins.push_back(c);
    }
    dp[0] = 1;
    for (int i = 1; i <= x; ++i){
        for (int c: coins){
            if (i - c >= 0) dp[i] = (dp[i] + dp[i - c]) % M;
        }
    }
    cout << dp[x];
}