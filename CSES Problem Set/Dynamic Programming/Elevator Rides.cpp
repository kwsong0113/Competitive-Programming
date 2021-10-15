#include <bits/stdc++.h>
using namespace std;
int n, x, w[20];
pair<int, int> dp[1 << 20];

int main(){
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> w[i];
    dp[0] = {1, 0};
    for (int s = 1; s < (1 << n); ++s){
        dp[s] = {n + 1, 0};
        for (int p = 0; p < n; ++p){
            if (s & (1 << p)){
                auto option = dp[s ^ (1 << p)];
                if (option.second + w[p] <= x){
                    option.second += w[p];
                }
                else {
                    option.first += 1; option.second = w[p];
                }
                dp[s] = min(dp[s], option);
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
}