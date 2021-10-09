#include <bits/stdc++.h>
using namespace std;
int t, a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> a >> b;
        if (2 * a >= b && 2 * b >= a && (2 * a - b) % 3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}