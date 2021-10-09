#include <bits/stdc++.h>
using namespace std;
long long sum, sum1;
int n, minDiff = INT_MAX;
int p[21], binary[21];

void search(int i){
    if (i > n) return;
    search(i + 1);
    if (binary[i]) sum1 -= p[i];
    else sum1 += p[i];
    binary[i] ^= 1;
    minDiff = min(abs(2 * sum1 - sum), (long long)minDiff);
    search(i + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> p[i];
        sum += p[i];
    }
    search(1);
    cout << minDiff;
}