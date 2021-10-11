#include <bits/stdc++.h>
using namespace std;
int n, x, p, l, r;
set<int> pos;
multiset<int> passage;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> n;
    pos.insert(0); pos.insert(x); passage.insert(x);
    for (int i = 1; i <= n; ++i){
        cin >> p;
        auto it = pos.upper_bound(p);
        r = *it;
        it--; l = *it;
        passage.insert(r - p); passage.insert(p - l);
        passage.erase(passage.find(r - l));
        pos.insert(p);
        it = passage.end(); it--;
        cout << *it << " ";
    }
}          
