#include <bits/stdc++.h>
using namespace std;
int n, x, a[5001];
map<int, pair<int, int>> num;

void solve(){
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 3; i <= n - 1; ++i){
        for (int j = i - 2; j >= 1; --j) num[a[j] + a[i - 1]] = {j, i - 1};
        for (int k = i + 1; k <= n; ++k) {
            if (num.count(x - a[i] - a[k])){
                cout << num[x - a[i] - a[k]].first << " " << num[x - a[i] - a[k]].second << " "<< i << " " << k;
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