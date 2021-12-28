#include <bits/stdc++.h>
using namespace std;
int t, n, num, cnt;
multiset<int> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> num; a.insert(num);
        }
        cnt = 0;
        for (int i = n; i >= 1; --i){
            auto it = a.lower_bound(i);
            if (it == a.end()){
                cnt = -1; break;
            }
            if (*it == i){
                a.erase(it); continue;
            }
            it = a.lower_bound(2 * i + 1);
            if (it == a.end()){
                cnt = -1; break;
            }
            a.erase(it); cnt++;
        }
        a.clear();
        cout << cnt << "\n";
    }
}