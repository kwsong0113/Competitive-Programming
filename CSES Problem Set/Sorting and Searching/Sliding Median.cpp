#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int n, k, x[200001];
indexed_set T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i){
        cin >> x[i]; T.insert({x[i], i});
    }
    cout << (*T.find_by_order((k - 1) / 2)).first << " ";
    for (int i = k + 1; i <= n; ++i){
        cin >> x[i];
        T.insert({x[i], i}); T.erase({x[i - k], i - k});
        cout << (*T.find_by_order((k - 1) / 2)).first << " ";
    }
}