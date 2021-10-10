#include <bits/stdc++.h>
using namespace std;
int n, x[200001];
long long num;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i){
        if (x[i] > num + 1){
            cout << num + 1;
            return 0;
        }
        else num += x[i];
    }
    cout << num + 1;
}