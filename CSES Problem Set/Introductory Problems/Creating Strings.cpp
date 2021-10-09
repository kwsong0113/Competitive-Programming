#include <bits/stdc++.h>
using namespace std;
string s, t;
map<char, int> num;
void search(int i){
    if (i == s.size()){
        cout << t << "\n";
        return;
    }
    for (pair<char, int> x: num){
        if (!x.second) continue;
        t[i] = x.first;
        num[x.first]--;
        search(i + 1);
        num[x.first]++;
    }
}

int fac(int m){
    if (!m) return 1;
    return m * fac(m - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    t = string(s.size(), 'a');
    for (char c: s) num[c]++;
    int tot = fac(s.size());
    for (pair<char, int> x: num) tot /= fac(x.second);
    cout << tot << "\n";
    search(0);
}

