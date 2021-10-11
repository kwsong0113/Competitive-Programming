#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
int n, k, idx;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) T.insert(i);
    while (n--){
        idx = (idx + k) % T.size();
        auto x = T.find_by_order(idx);
        cout << *x << " ";
        T.erase(x);
    }
}