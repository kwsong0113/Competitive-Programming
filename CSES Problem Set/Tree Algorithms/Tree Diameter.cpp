#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, a, b, maxLength, toLeaf[N];
vector<int> adj[N];

void dfs(int u, int e){
    int max1 = 0, max2 = 0;
    for (int v: adj[u]){
        if (v == e) continue;
        dfs(v, u);
        if (toLeaf[v] + 1 > max1){
            max2 = max1; max1 = toLeaf[v] + 1;
        }
        else if (toLeaf[v] + 1 > max2){
            max2 = toLeaf[v] + 1;
        }
    }
    toLeaf[u] = max1;
    maxLength = max(max1 + max2, maxLength);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << maxLength;
}