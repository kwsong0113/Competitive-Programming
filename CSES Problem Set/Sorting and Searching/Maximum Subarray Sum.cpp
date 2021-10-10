#include <bits/stdc++.h>
using namespace std;
int n, x;
long long sum, maxSum = LLONG_MIN;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        sum = max(1LL * x, sum + x);
        maxSum = max(maxSum, sum);
    }
    cout << maxSum;
}