#include <bits/stdc++.h>
using namespace std;
int n, x, a[5001];
map<int, int> num;

void solve(){
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n - 2; ++i){
        num[a[i]] = i;
        for (int k = i + 2; k <= n; ++k) {
            if (num.count(x - a[i + 1] - a[k])){
                cout << num[x - a[i + 1] - a[k]] << " " << (i + 1) << " " << k;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    solve();
}