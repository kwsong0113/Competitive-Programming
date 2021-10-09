#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n;

int power(int x, int y, int t){
    if (y == 0) return t;
    return power(1LL * x * x % M, y / 2, y & 1 ? 1LL * x * t % M : t);
}

int main(){
    cin >> n;
    cout << power(2, n, 1);
}