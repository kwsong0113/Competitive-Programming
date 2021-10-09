#include <bits/stdc++.h>
using namespace std;
string s;
int n, a, b, alpha[26];
int rem = -1;

int main(){
    cin >> s;
    n = s.size(), a = 0, b = n - 1;
    char ans[n];
    for (char c: s) alpha[c - 'A']++;
    for (int i = 0; i < 26; ++i){
        if (alpha[i] & 1){
            if (rem >= 0){
                cout << "NO SOLUTION";
                return 0;
            }
            rem = i;
        }
        for (int j = 0; j < alpha[i] / 2; ++j){
            ans[a + j] = ans[b - j] = 'A' + i;
        }
        a += alpha[i] / 2; b -= alpha[i] / 2;
    }
    if (n & 1){
        ans[n / 2] = 'A' + rem;
    }
    for (int i = 0; i < n; ++i) cout << ans[i];
    
}