#include <bits/stdc++.h>
using namespace std;
int n, m, k, num;
int a[200001], b[200001];

int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int i = 1, j = 1;
    while (i <= n && j <= m){
        if (b[j] >= a[i] - k && b[j] <= a[i] + k){
            num++; i++; j++;
        }
        else if (b[j] < a[i] - k) j++;
        else i++;
    }
    cout << num;
}