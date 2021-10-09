#include <bits/stdc++.h>
using namespace std;
int n, temp;
long long sum;

int main(){
    cin >> n;
    for (int i = 1; i < n; ++i){
        cin >> temp;
        sum += temp;
    }
    cout << (1LL * n * (n + 1) / 2 - sum);
}