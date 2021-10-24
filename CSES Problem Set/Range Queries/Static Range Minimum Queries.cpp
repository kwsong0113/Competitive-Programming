#include <bits/stdc++.h>
using namespace std;
const int N = 200001, M = 18;
int n, q, a, b, x, maxPower, minVal[M][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> minVal[0][i];
    }
    for (int i = 1; i <= floor(log2(n)); ++i){
        for (int j = 1; j <= n - (1 << i) + 1; ++j){
            minVal[i][j] = min(minVal[i - 1][j], minVal[i - 1][j + (1 << (i - 1))]);
        }
    }
    while (q--){
        cin >> a >> b;
        maxPower = floor(log2(b - a + 1));
        cout << min(minVal[maxPower][a], minVal[maxPower][b - (1 << maxPower) + 1]) << "\n";
    }    
}