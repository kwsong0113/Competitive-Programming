#include <bits/stdc++.h>
using namespace std;
string s;
int n;

void f(int m){
    if (!m) return;
    f(m - 1);
    s[m - 1] = (s[m - 1] == '1' ? '0' : '1');
    cout << s << "\n";
    f(m - 1);
}


int main(){
    cin >> n;
    s = string(n, '0');
    cout << s << "\n";
    f(n);
}