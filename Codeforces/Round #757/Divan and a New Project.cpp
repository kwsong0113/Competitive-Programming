#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int t, n, aIn, x[N];
pair<int, int> a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> aIn; a[i] = {aIn, i};
        }
        sort(a + 1, a + n + 1, greater<pair<int, int>>());
        long long T = 0;
        for (int i = 1; i <= n; ++i){
            x[a[i].second] = i % 2 ? (i + 1) / 2 : -((i + 1) / 2);
            T += 1LL * 2 * a[i].first * abs(x[a[i].second]);
        }
        cout << T << "\n";
        for (int i = 0; i <= n; ++i) cout << x[i] << " ";
        cout << "\n";
    }
}