#include <bits/stdc++.h>
using namespace std;
const int N = 270000;
int n, newN, p, pos, x[N], tree[2 * N];

int query(int a, int b){
    int sum = 0;
    a += newN - 1; b += newN - 1;
    while (a <= b){
        if (a % 2 == 1) sum += tree[a++];
        if (b % 2 == 0) sum += tree[b--];
        a /= 2; b /= 2;
    }
    return sum;
}

void update(int k, int x){
    k += newN - 1;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2){
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

int search(int a, int b, int x){
    if (a == b) return a;
    int mid = (a + b) / 2;
    if (mid - query(1, mid) >= x) return search(a, mid, x);
    else return search(mid + 1, b, x);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    newN = 1 << (int)ceil(log2(n));
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i){
        cin >> p;
        pos = search(1, n, p);
        update(pos, 1);
        cout << x[pos] << " ";
    }
}