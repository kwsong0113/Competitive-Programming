#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, a, b, numComp, maxSize, compSize[N], link[N];

int find(int x){
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (compSize[a] < compSize[b]) swap(a, b);
    compSize[a] += compSize[b];
    link[b] = a;
    numComp--;
    maxSize = max(maxSize, compSize[a]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    numComp = n; maxSize = 1;
    for (int i = 1; i <= n; ++i){
        compSize[i] = 1; link[i] = i;
    }
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        unite(a, b);
        cout << numComp << " " << maxSize << "\n";
    }
}