#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, q, a, b, x[N], tree[N], ans[N];
vector<pair<int, int>> query[N];
map<int, int> firstIdx;

void add(int k, int x){
    while (k <= n){
        tree[k] += x;
        k += k & -k;
    }
}

int sum(int k){
    int s = 0;
    while (k >= 1){
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= q; ++i){
        cin >> a >> b;
        query[a].push_back({b, i});
    }
    for (int i = n; i >= 1; --i){
            if (firstIdx.count(x[i])) add(firstIdx[x[i]], -1);
            firstIdx[x[i]] = i;
            add(i, 1);
        for (auto [j, k]: query[i]){
            ans[k] = sum(j);
        }
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << "\n";
}