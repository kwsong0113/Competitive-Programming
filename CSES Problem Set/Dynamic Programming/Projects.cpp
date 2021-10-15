#include <bits/stdc++.h>
using namespace std;
int n;
typedef array<int, 3> triple;
triple project[200001];
long long dp[200001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> project[i][1] >> project[i][0] >> project[i][2];
    }
    sort(project + 1, project + n + 1);
    for (int i = 1; i <= n; ++i){
        auto it = lower_bound(project + 1, project + n + 1, triple{project[i][1], 0, 0});
        it--;
        dp[i] = max(dp[i - 1], dp[it - project] + project[i][2]);
    }
    cout << dp[n];
}