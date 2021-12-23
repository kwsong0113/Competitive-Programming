#include <bits/stdc++.h>
using namespace std;
int t;
string S, T;

bool comp(const char &a, const char &b){
    char A = (a == 'b' ? 'c' : (a == 'c' ? 'b' : a));
    char B = (b == 'b' ? 'c' : (b == 'c' ? 'b' : b));
    if (A < B) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> S >> T;
        sort(S.begin(), S.end());
        if (T == "abc" && S[0] == 'a') sort(S.begin(), S.end(), comp);
        cout << S << "\n";
    }
}