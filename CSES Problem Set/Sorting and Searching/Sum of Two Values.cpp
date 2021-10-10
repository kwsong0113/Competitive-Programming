#include <bits/stdc++.h>
using namespace std;
int n, x, a[200001], b[200001];

bool cmp(int i, int j){
    return a[i] < a[j];
}

void solve(){
    for(int i = 1; i <= n; ++i) b[i] = i;
    sort(b + 1, b + n + 1, cmp);
    sort(a + 1, a + n + 1);
    int i = 1, j = n;
    while (i < j){
        if (a[i] + a[j] > x) j--;
        else if (a[i] + a[j] < x) i++;
        else {
            cout << b[i] << " " << b[j];
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    solve();  
}