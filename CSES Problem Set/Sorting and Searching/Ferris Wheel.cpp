#include <bits/stdc++.h>
using namespace std;
int n, x, p[200001], num;

int main(){
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    sort(p + 1, p + n + 1);
    int i = 1, j = n;
    while (i <= j){
        num++;
        if (i == j) break;
        if (p[i] + p[j] <= x){
            i++; j--;
        }
        else j--;      
    }
    cout << num;
}