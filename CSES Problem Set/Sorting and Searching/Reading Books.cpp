#include <bits/stdc++.h>
using namespace std;
int n, t[200001], maxTime;
long long sum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> t[i];
        maxTime = max(maxTime, t[i]);
        sum += t[i];
    }
    cout << max(1LL * 2 * maxTime, sum);
}