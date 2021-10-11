#include <bits/stdc++.h>
using namespace std;
int n, k;
multiset<int> tower;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> k;
        auto it = tower.upper_bound(k);
        if (it == tower.end()) tower.insert(k);
        else {
            tower.erase(it); tower.insert(k);
        }
    }
    cout << tower.size();
}