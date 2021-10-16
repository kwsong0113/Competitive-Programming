#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n, m, dp[1001][1024];
vector<int> val[1024];

bool valid(int x, int y){
    int num = 0;
    for (int i = 1; i <= n; ++i){
        if ((x & 1) & y) return false;
        else if ((x & 1) ^ (y & 1)){
            if (num & 1) return false;
            num = 0;
        }
        else num += 1; 
        x >>= 1; y >>= 1;
    }
    if (num & 1) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if (m == 1){
        cout << ((n & 1) ^ 1); return 0;
    }
    for (int x = 0; x < (1 << n); ++x){
        for (int y = 0; y < (1 << n); ++y){
            if (valid(x, y)) val[x].push_back(y);
        }
    }
    
    for (int i = 0; i < (1 << n); ++i){
        if (valid(i, 0)) dp[1][i] = 1;
    }
    for (int i = 2; i <= m; ++i){
        for (int j = 0; j < (1 << n); ++j){
            for (int k: val[j]){
                (dp[i][j] += dp[i - 1][k]) %= M;
            }
        }
    }
    cout << dp[m][0];
}