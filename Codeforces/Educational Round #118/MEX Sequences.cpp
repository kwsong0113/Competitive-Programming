#include <bits/stdc++.h>
using namespace std;
const int N = 500001, M = 998244353;
int t, n, a, dp1[N], dp2[N];

int add(int x, int y){
    return (x + y) % M;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0; i <= n; ++i){
            dp1[i] = dp2[i] = 0;
        }
        dp1[0] = 1;
        for (int i = 1; i <= n; ++i){
            cin >> a;
            dp1[a + 1] = add(dp1[a + 1], dp1[a + 1]);
            dp1[a + 1] = add(dp1[a + 1], dp1[a]);
            dp2[a + 1] = add(dp2[a + 1], dp2[a + 1]);
            if (a > 0){
                dp2[a - 1] = add(dp2[a - 1], dp2[a - 1]);
                dp2[a - 1] = add(dp2[a - 1], dp1[a - 1]);
            }
            
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i){
            ans = add(ans, dp1[i]); ans = add(ans, dp2[i]);
        }
        cout << add(ans, M - 1) << "\n";
    }
}