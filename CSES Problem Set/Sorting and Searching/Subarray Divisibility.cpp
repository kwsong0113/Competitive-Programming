#include <bits/stdc++.h>
using namespace std;
int n, a, sum, sumCount[200001];
long long num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    sumCount[0] += 1;
    for (int i = 1; i <= n; ++i){
        cin >> a;
        sum = (sum + a % n + n) % n;
        sumCount[sum]++;
    }
    for (int i = 0; i < n; ++i){
        num += 1LL * sumCount[i] * (sumCount[i] - 1) / 2;
    }
    cout << num;
}