#include <bits/stdc++.h>
using namespace std;
int n, a, b, x;
long long maxSum = LLONG_MIN, sumMem[200001];
multiset<long long> sumSet;

int main(){
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        sumMem[i] = sumMem[i - 1] + x;
        if (i - a >= 0) sumSet.insert(sumMem[i - a]);
        if (i - 1 - b >= 0) sumSet.erase(sumSet.find(sumMem[i - 1 - b]));
        if (!sumSet.empty()) maxSum = max(maxSum, sumMem[i] - *sumSet.begin());
    }
    cout << maxSum;
}