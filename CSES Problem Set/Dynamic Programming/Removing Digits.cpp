#include <bits/stdc++.h>
using namespace std;
int n, dp[1000001];
const int INF = INT_MAX;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        dp[i] = INF;
        int j = i;
        while (j > 0){
            if ((j % 10)) dp[i] = min(dp[i], dp[i - j % 10] + 1);
            j /= 10;
        }
    }
    cout << dp[n];
}