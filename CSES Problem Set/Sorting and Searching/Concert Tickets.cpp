#include <bits/stdc++.h>
using namespace std;
int n, m, h, t;
multiset<int> hSet;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> h;
        hSet.insert(h);
    }
    for (int i = 1; i <= m; ++i){
        cin >> t;
        auto it = hSet.upper_bound(t);
        if (it == hSet.begin()) cout << "-1\n";
        else {
            cout << *(--it) << "\n";
            hSet.erase(it);
        }
    }
}