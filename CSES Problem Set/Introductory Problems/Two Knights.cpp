#include <bits/stdc++.h>
using namespace std;
int n;
long long num;


int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cout << 1LL * i * i * (i * i  - 1) / 2 - 4 * (i - 1) * (i - 2) << "\n";
    }
}