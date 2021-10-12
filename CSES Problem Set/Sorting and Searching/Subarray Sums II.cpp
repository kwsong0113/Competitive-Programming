#include <bits/stdc++.h>
using namespace std;
int n, x, a;
long long num;
long long sum;
map<long long, int> sumMap;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    sumMap[0]++;
    for (int i = 1; i <= n; ++i){
        cin >> a;
        sum += a;
        if (sumMap.count(sum - x)) num += sumMap[sum - x];
        sumMap[sum]++;
    }
    cout << num;
}