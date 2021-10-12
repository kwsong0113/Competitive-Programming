#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int n, k, x[200001];
indexed_set T;
long long sum1, sum2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int pos = (k - 1) / 2;
    for (int i = 1; i <= k; ++i){
        cin >> x[i]; T.insert({x[i], i});
        sum1 += x[i];
    }
    for (int i = 0; i <= pos; ++i){
        sum2 += (*T.find_by_order(i)).first;
    }
    
    cout << (sum1 - 2 * sum2 + (k & 1) * (*T.find_by_order(pos)).first) << " ";
    for (int i = k + 1; i <= n; ++i){
        cin >> x[i];
        sum1 += (x[i] - x[i - k]);
        if (T.order_of_key({x[i - k], i - k}) <= pos){
            sum2 -= x[i - k];
            T.erase({x[i - k], i - k});
            T.insert({x[i], i});
            if (T.order_of_key({x[i], i}) <= pos) sum2 += x[i];
            else sum2 += (*T.find_by_order(pos)).first;
        }
        else {
            T.erase({x[i - k], i - k});
            T.insert({x[i], i});
            if (T.order_of_key({x[i], i}) <= pos) sum2 += (x[i] - (*T.find_by_order(pos + 1)).first);
        }
        cout << (sum1 - 2 * sum2 + (k & 1) * (*T.find_by_order(pos)).first) << " ";
    }
}
