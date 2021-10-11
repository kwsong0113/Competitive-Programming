#include <bits/stdc++.h>
using namespace std;
int n, x, y, maxLen;
tuple<int, int, int> ranges[200001];
int ans[2][200001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x >> y;
        ranges[i] = make_tuple(x, -y, i);
    }
    sort(ranges + 1, ranges + n + 1);
    for (int i = 1; i <= n; ++i){
        if (get<1>(ranges[i]) >= maxLen) ans[1][get<2>(ranges[i])] = 1;
        else maxLen = get<1>(ranges[i]);
    }
    maxLen = INT_MIN;
    for (int i = n; i >= 1; --i){
        if (get<1>(ranges[i]) <= maxLen) ans[0][get<2>(ranges[i])] = 1;
        else maxLen = get<1>(ranges[i]);
    }
    for (int i = 0; i < 2; ++i){
        for (int j = 1; j <= n; ++j){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
}