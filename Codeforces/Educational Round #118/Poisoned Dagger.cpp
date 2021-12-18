#include <bits/stdc++.h>
using namespace std;
int t, n, a[101];
long long h;

long long damage(long long k){
    long long ans = k;
    for (int i = 1; i < n; ++i) ans += min((long long)(a[i + 1] - a[i]), k);
    return ans;
}

long long search(long long l, long long r, long long val){
    if (l == r) return l;
    long long mid = (l + r) / 2;
    if (damage(mid) >= val) return search(l, mid, val);
    return search(mid + 1, r, val);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> h;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cout << search(1, h, h) << "\n";
    }
}