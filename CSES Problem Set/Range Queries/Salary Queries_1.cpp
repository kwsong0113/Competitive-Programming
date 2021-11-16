#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int N = 200001;
int n, q, a, b, s[N];
char opt;
indexed_set salary;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> s[i]; salary.insert({s[i], i});
    }
    while (q--){
        cin >> opt >> a >> b;
        if (opt == '!'){
            salary.erase({s[a], a});
            s[a] = b;
            salary.insert({b, a});
        }
        else {
            cout << (salary.order_of_key({b + 1, 0}) - salary.order_of_key({a, 0})) << "\n";
        }
    }
}