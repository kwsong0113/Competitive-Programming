#include <bits/stdc++.h>
using namespace std;
int t, n, l, r, k, a[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> l >> r >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; ++i){
            if (a[i] >= l && a[i] <= r){
                if (k >= a[i]){
                    cnt += 1; k -= a[i];
                } else break;
            }
        }
        cout << cnt << "\n";
    }
}
