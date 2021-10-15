#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> dp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else {
            dp[it - dp.begin()] = x;
        }
    }
    cout << dp.size();
}