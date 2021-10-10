#include <bits/stdc++.h>
using namespace std;
int q, numDigit;
long long power[17], start[17], k, num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    power[0] = start[0] = 1;
    for (int i = 1; i <= 16; ++i){
        power[i] = 10 * power[i - 1];
        start[i] = start[i - 1] + i * 9 * power[i - 1];
    }
    cin >> q;
    while (q--){
        cin >> k;
        auto it = lower_bound(start, start + 17, k + 1);
        it--;
        numDigit = it - start + 1;
        long long num = power[numDigit - 1];
        num += (k - *it) / numDigit;
        cout << (num / power[numDigit - (k - *it) % numDigit - 1]) % 10 << "\n";
        
    }
}