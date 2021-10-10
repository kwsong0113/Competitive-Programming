#include <bits/stdc++.h>
using namespace std;
int n, p[200001];
long long sum, sum1, minCost = LLONG_MAX;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> p[i];
        sum += p[i];
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i){
        sum1 += p[i];
        minCost = min(minCost, sum - 2 * sum1 - 1LL * p[i] * (n - 2 * i));
    }
    cout << minCost;
}