#include <bits/stdc++.h>
using namespace std;
int n, x[200001], ord[200001], ans[200001];
set<int> idx;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x[i];
        ord[i] = i;
    }
    sort(ord + 1, ord + n + 1, [](int i , int j){
        return (x[i] == x[j] ? i > j : x[i] < x[j]);
    });
    for (int i = 1; i <= n; ++i){
        auto it = idx.lower_bound(ord[i]);
        if (it == idx.begin()) ans[ord[i]] = 0;
        else {
            it--;
            ans[ord[i]] = *it;
        }
        idx.insert(ord[i]);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}