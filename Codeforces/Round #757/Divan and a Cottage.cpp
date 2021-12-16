#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxT = 1e9, mod = 1e9 + 1;
int n, T, k, x, num, ans;
indexed_set ranges;

int f(int x){
    return x + num - ranges.order_of_key({x, 0});
}

int search(int l, int r, int val, bool opt){
    if (l == r){
        if (f(l) == val) return l;
        else if (f(l) > val) return -1;
        else return maxT + 1;
    }
    int mid = (l + r + opt) / 2;
    if (opt){
        if (f(mid) <= val) return search(mid, r, val, opt);
        return search(l, mid - 1, val, opt);
    } else {
        if (f(mid) >= val) return search(l, mid, val, opt);
        return search(mid + 1, r, val, opt);
    }
}

void update(){
    int aVal = search(0, maxT, T, false);
    int bVal = search(0, maxT, T, true);
    num++;
    ranges.insert({aVal, -num}); ranges.insert({bVal, num});
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> T;
        update();
        cin >> k;
        while (k--){
            cin >> x;
            x = (x + ans) % mod;
            cout << (ans = f(x)) << "\n";
        }
    }
}