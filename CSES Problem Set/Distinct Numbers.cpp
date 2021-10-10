#include <bits/stdc++.h>
using namespace std;
int n;
int x[200001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    sort(x + 1, x + n + 1);
    int num = 1;
    for (int i = 1; i <= n - 1; ++i){
        if (x[i] != x[i + 1]) num += 1;
    }
    cout << num;
}