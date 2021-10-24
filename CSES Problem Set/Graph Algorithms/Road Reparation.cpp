#include <bits/stdc++.h>
using namespace std;
typedef array<int, 3> triple;
const int N = 100001;
int link[N], num[N];
int n, m, a, b, c, added;
long long cost;
vector<triple> edges;

int find(int x){
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (num[a] < num[b]) swap(a, b);
    link[b] = a;
    num[a] += num[b];
    cost += c;
    added += 1;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        edges.push_back(triple{c, a, b});
    }
    sort(edges.begin(), edges.end());
    
    for (int i = 1; i <= n; ++i){
        link[i] = i; num[i] = 1;
    }
    for (triple e: edges){
        c = e[0]; a = e[1]; b = e[2];
        unite(a, b);
    }
    if (added < n - 1) cout << "IMPOSSIBLE";
    else cout << cost;
}