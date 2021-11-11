#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, q, x, a, b, sum[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        sum[i] = sum[i - 1] ^ x;
    }
    while (q--){
        cin >> a >> b;
        cout << (sum[b] ^ sum[a - 1]) << "\n";
    }
}