#include <bits/stdc++.h>
using namespace std;
int n, temp, x = INT_MIN;
long long sum;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> temp;
        if (temp >= x) x = temp;
        else sum += x - temp;
    }
    cout << sum;
}