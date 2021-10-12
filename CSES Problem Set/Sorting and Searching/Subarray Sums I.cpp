#include <bits/stdc++.h>
using namespace std;
int n, x, a, num;
long long sum;
set<long long> sumSet;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    sumSet.insert(0);
    for (int i = 1; i <= n; ++i){
        cin >> a;
        sum += a;
        if (sumSet.count(sum - x)) num += 1;
        sumSet.insert(sum);
    }
    cout << num;
}