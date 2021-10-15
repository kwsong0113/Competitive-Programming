#include <bits/stdc++.h>
using namespace std;
int n, x, num;
bool dp[101][100001];

int main(){
    cin >> n;
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        for (int j = 0; j <= 1000 * i; ++j){
            dp[i][j] = dp[i - 1][j];
            if (!dp[i][j] && j >= x && dp[i - 1][j - x]){
                dp[i][j] = true; num++;
            }
        }
    }
    cout << num << "\n";
    for (int i = 1; i <= 1000 * n; ++i){
        if (dp[n][i]) cout << i << " ";
    } 
}