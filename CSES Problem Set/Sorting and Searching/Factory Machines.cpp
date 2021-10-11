#include <bits/stdc++.h>
using namespace std;
int n, k[200001];
long long t;

bool valid(long long x){
    long long sum = 0;
    for (int i = 1; i <= n; ++i) sum += x / k[i];
    return sum >= t;
}

long long search(long long l, long long r){
    if (l == r) return l;
    long long mid = (l + r) / 2;
    if (valid(mid)) return search(l, mid);
    else return search(mid + 1, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> k[i];
    cout << search(1, t * (*min_element(k + 1, k + n + 1)));
}