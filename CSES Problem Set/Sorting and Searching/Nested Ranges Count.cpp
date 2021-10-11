#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef array<int, 3> triple;
int n, x, y;
triple ranges[200001];
int ans[2][200001];
indexed_set T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x >> y;
        ranges[i] = {x, y, i};
    }
    sort(ranges + 1, ranges + n + 1, [](triple A, triple B){
        return (A[0] == B[0] ? A[1] > B[1] : A[0] < B[0]);
    });
    for (int i = 1; i <= n; ++i){
        ans[1][ranges[i][2]] = T.size() - T.order_of_key({ranges[i][1], -1});
        T.insert({ranges[i][1], i});
    }
    T.clear();
    for (int i = n; i >= 1; --i){
        ans[0][ranges[i][2]] = T.order_of_key({ranges[i][1] + 1, -1});
        T.insert({ranges[i][1], i});
    }
    
    for (int i = 0; i < 2; ++i){
        for (int j = 1; j <= n; ++j) cout << ans[i][j] << " ";
        cout << "\n";
    }
    
}