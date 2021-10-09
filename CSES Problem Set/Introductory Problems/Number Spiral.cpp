#include <bits/stdc++.h>
using namespace std;
int t, x, y, step;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> y >> x;
        step = max(x, y);
        if (step & 1){
            cout << (x > y ? 1LL * step * step + 1 - y : 1LL * (step - 1) * (step - 1) + x);
        }
        else {
            cout << (x < y ? 1LL * step * step + 1 - x : 1LL * (step - 1) * (step - 1) + y);
        }
        cout << "\n";
    }
}