#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, q, a, b, opt, val0[N], val[N], ord[N], subTree[N], cnt = 1;
long long bit[N];
vector<int> adj[N];

void dfs(int u, int prev){
    ord[u] = cnt++;
    subTree[u] = 1;
    for (int v: adj[u]){
        if (v != prev){
            dfs(v, u);
            subTree[u] += subTree[v];
        }
    }
}

void setVal(int u, int x){
    int k = ord[u], delta = x - val[u];
    while (k <= n){
        bit[k] += delta;
        k += k & -k;
    }
    val[u] = x;
}

long long sum(int k){
    long long s = 0;
    while (k >= 1){
        s += bit[k];
        k -= k & -k;
    }
    return s;
}

long long subTreeSum(int u){
    return sum(ord[u] + subTree[u] - 1) - sum(ord[u] - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> val0[i];
    }
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) setVal(i, val0[i]);
    while (q--){
        cin >> opt;
        if (opt == 1){
            cin >> a >> b; setVal(a, b);
        } else {
            cin >> a; cout << subTreeSum(a) << "\n";
        }
    }
}