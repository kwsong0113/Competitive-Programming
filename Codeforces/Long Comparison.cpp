#include <bits/stdc++.h>
using namespace std;
int t, x1, p1, x2, p2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> x1 >> p1 >> x2 >> p2;
        while (x1 <= 100000){
            x1 *= 10; p1--;
        }
        while (x2 <= 100000){
            x2 *= 10; p2 --;
        }
        if (x1 == x2 && p1 == p2) cout << "=";
        else if (p1 == p2) cout << ((x1 > x2) ? ">" : "<");
        else cout << ((p1 > p2) ? ">" : "<");
        cout << "\n";
    }
}