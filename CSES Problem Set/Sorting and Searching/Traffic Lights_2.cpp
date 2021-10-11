#include <bits/stdc++.h>
using namespace std;
int n, x, p, l, r;
set<int> pos;
int light[200001], ans[200001], maxLen;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> n;
    pos.insert(0); pos.insert(x);
    for (int i = 1; i <= n; ++i){
        cin >> light[i];
        pos.insert(light[i]);
    }
    int x = 0, y = 0;
    auto it = pos.begin();
    for (int i = 1; i <= n + 1; ++i){
        it++; y = *it;
        maxLen = max(maxLen, y - x);
        x = y;
    }
    ans[n] = maxLen;
    for (int i = n; i >= 2; --i){
        it = pos.upper_bound(light[i]);
        maxLen = *it; it--; it--;
        maxLen -= *it;
        ans[i - 1] = max(maxLen, ans[i]);
        pos.erase(++it);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}          
