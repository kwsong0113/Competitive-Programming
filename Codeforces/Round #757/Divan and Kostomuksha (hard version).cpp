#include <bits/stdc++.h>
using namespace std;
const int M = 2e7 + 1;
int n, a;
long long numOfMultiples[M], dp[M];
bool vis[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a;
        for (int j = 1; j * j <= a; ++j){
            if (!(a % j)){
                numOfMultiples[j] ++; numOfMultiples[a / j] += ((j * j) != a);
            }
        }
    }
    for (int i = M - 1; i >= 1; --i){
        if (!numOfMultiples[i]) continue;
        dp[i] = i * numOfMultiples[i];
        for (int j = i; j <= M - 1; j += i){
            if (!numOfMultiples[j]) continue;
            dp[i] = max(dp[i], dp[j] + (numOfMultiples[i] - numOfMultiples[j]) * i);
        }
    }
    cout << dp[1];
}