#include <bits/stdc++.h>
using namespace std;
int t, n, a, b, c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        if (n % 2){
            a = (n + n % 4) / 2;
        } else {
            a = n - 3;
        }
        c = 1; b = n - a - c;
        cout << a << " " << b << " " << c << "\n";
    }
}