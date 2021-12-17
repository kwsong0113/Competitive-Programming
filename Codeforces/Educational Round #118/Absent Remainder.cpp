#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int t, n, minVal, num, a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        minVal = INT_MAX, num = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            minVal = min(minVal, a[i]);
        }
        for (int i = 1; i <= n; ++i){
            if (a[i] != minVal){
                cout << a[i] << " " << minVal << "\n"; num++;
            }
            if (num == n / 2) break;
        }
    }
}