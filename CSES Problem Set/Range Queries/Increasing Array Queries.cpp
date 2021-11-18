#include <bits/stdc++.h>
using namespace std;
const int N = 200002;
int n, q, a, b, x[N];
long long pref[N], contrib[N], ans[N], tree[N];
vector<pair<int, int>> rem[N];
deque<int> stck;

void update(int k, long long x){
    while (k <= n){
        tree[k] += x; k += k & -k;
    }
}

long long query(int a, int b){
    long long s = 0;
    while (b >= 1){
        s += tree[b]; b -= b & -b;
    }
    a--;
    while (a >= 1){
        s -= tree[a]; a -= a & -a;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> x[i]; pref[i] = pref[i - 1] + x[i];
    }
    for (int i = 1; i <= q; ++i){
        cin >> a >> b;
        rem[a].push_back({b, i});
    }
    stck.push_front(n + 1); x[n + 1] = INT_MAX;
    for (int i = n; i >= 1; --i){
        while (x[i] >= x[stck.front()]){
            update(stck.front(), -contrib[stck.front()]);
            stck.pop_front();
        }
        contrib[i] = 1LL * (stck.front() - 1 - i) * x[i] - (pref[stck.front() - 1] - pref[i]);
        update(i, contrib[i]); stck.push_front(i);
        for (auto [j, k]: rem[i]){
            int pos = upper_bound(stck.begin(), stck.end(), j) - stck.begin() - 1;
            ans[k] = (pos ? query(i, stck[pos - 1]) : 0) + 1LL * (j - stck[pos]) * x[stck[pos]] - (pref[j] - pref[stck[pos]]);
        }
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << "\n";
}
