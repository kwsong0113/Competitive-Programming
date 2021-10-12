#include <bits/stdc++.h>
using namespace std;
int n, k, x[200001];
long long sum;

bool valid(long long val){
    int num = 1;
    long long currentSum = 0;
    for (int i = 1; i <= n; ++i){
        currentSum += x[i];
        if (currentSum > val){
            currentSum = x[i]; num++;
        }
    }
    return (num <= k);
}

long long search(long long l, long long r){
    if (l == r) return l;
    long long mid = (l + r) / 2;
    if (valid(mid)) return search(l, mid);
    return search(mid + 1, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> x[i];
        sum += x[i];
    }
    cout << search(*max_element(x + 1, x + n + 1), sum);
}