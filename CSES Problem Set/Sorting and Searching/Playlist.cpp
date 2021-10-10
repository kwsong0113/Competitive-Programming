#include <bits/stdc++.h>
using namespace std;
int n, k[200001], ord1[200001], ord2[200001];
int len, maxLen;

bool cmp(int i, int j){
    if (k[i] == k[j]) return i < j;
    else return k[i] < k[j];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> k[i];
        ord1[i] = i;
    }
    sort(ord1 + 1, ord1 + n + 1, cmp);
    for (int i = 1; i <= n; ++i) ord2[ord1[i]] = i;
    for (int i = 1; i <= n; ++i){
        if (ord2[i] == 1) len += 1;
        else {
            if (k[ord1[ord2[i] - 1]] == k[i]) len = min(len + 1, i - ord1[ord2[i] - 1]);
            else len += 1;
        }
        maxLen = max(maxLen, len);
    }
    cout << maxLen;
}