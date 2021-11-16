#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int N = 200001;
int n, p, x[N];
indexed_set T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n; ++i){
        cin >> x[i];
        T.insert(i);
    }
    for (int i = 1; i <= n; ++i){
        cin >> p;
        auto it = T.find_by_order(p - 1);
        cout << x[*it] << " ";
        T.erase(it);
    }
}