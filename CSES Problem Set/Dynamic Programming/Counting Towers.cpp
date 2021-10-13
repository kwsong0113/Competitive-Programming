#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n, t, x[2][1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    x[0][1] = x[1][1] = 1;
    for (int i = 2; i <= 1e6; ++i){
        x[0][i] = (1LL * 2 * x[0][i - 1] + x[1][i - 1]) % M;
        x[1][i] = (1LL * 4 * x[1][i - 1] + x[0][i - 1]) % M;
    }
    cin >> t;
    while (t--){
        cin >> n;
        cout << (x[0][n] + x[1][n]) % M << "\n";
    }
}