#include <bits/stdc++.h>
using namespace std;
int n, temp, num = 1, ord[200001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> temp;
        ord[temp] = i;
    }
    for (int i = 1; i <= n - 1; ++i){
        num += (ord[i + 1] < ord[i]);
    }
    cout << num;
}