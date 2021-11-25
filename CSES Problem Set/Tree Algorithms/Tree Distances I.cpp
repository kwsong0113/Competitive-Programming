#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, a, b, maxLengthUp[N], maxLength1[N], maxLength2[N];
vector<int> adj[N];

void dfsDown(int u, int e){
    for (int v: adj[u]){
        if (v == e) continue;
        dfsDown(v, u);
        if (maxLength1[v] + 1 > maxLength1[u]){
            maxLength2[u] = maxLength1[u]; maxLength1[u] = maxLength1[v] + 1;
        }
        else if (maxLength1[v] + 1 > maxLength2[u]){
            maxLength2[u] = maxLength1[v] + 1;
        }
    }
}

void dfsUp(int u, int e){
    if (e != 0){
        maxLengthUp[u] = (maxLength1[e] == maxLength1[u] + 1) ? (maxLength2[e] + 1) : (maxLength1[e] + 1);
        maxLengthUp[u] = max(maxLengthUp[u], maxLengthUp[e] + 1);
    }
    for (int v: adj[u]){
        if (v == e) continue;
        dfsUp(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfsDown(1, 0);
    dfsUp(1, 0);
    for (int i = 1; i <= n; ++i) cout << max(maxLengthUp[i], maxLength1[i]) << " ";
}