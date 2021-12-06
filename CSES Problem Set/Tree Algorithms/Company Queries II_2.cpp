#include <bits/stdc++.h>
using namespace std;
const int N = 200001, M = 18;
int n, q, logVal, a, b, e, cnt, up[M][N], st[N], en[N];
vector<int> adj[N];

void dfs(int u){
    st[u] = cnt++;
    for (int i = 1; i <= logVal; ++i){
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for (int v: adj[u]){
        if (v != up[0][u]){
            up[0][v] = u; dfs(v);
        }
    }
    en[u] = cnt;
}

bool anc(int a, int b){
    return st[a] <= st[b] && en[a] >= en[b];
}

int LCA(int a, int b){
    if (anc(a, b)) return a;
    if (anc(b, a)) return b;
    for (int i = logVal; i >= 0; --i){
        if (!anc(up[i][a], b)) a = up[i][a];
    }
    return up[0][a];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; ++i){
        cin >> e; adj[e].push_back(i);
    }
    logVal = floor(log2(n));
    up[0][1] = 1; dfs(1);
    
    while (q--){
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}
