#include <bits/stdc++.h>
using namespace std;
int n, a[200001], d;
long long now, sum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i] >> d;
        sum += d;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i){
        now += a[i];
        sum -= now;
    }
    cout << sum;
}