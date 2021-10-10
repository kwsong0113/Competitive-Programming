#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, A, B, x[200001], ord[200001], num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> x[i];
        ord[x[i]] = i;
    }
    num = 1;
    for (int i = 1; i <= n - 1; ++i) num += (ord[i] > ord[i + 1]);
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        A = x[a]; B = x[b];
        if (A > B){
            swap(A, B);
        }
        num -= (A > 1 && ord[A - 1] > ord[A]) + (ord[A] > ord[A + 1]) + (ord[B - 1] > ord[B]) + (B < n && ord[B] > ord[B + 1]) - (B == A + 1 && ord[A] > ord[B]);
        swap(ord[A], ord[B]); swap(x[a], x[b]);
        num += (A > 1 && ord[A - 1] > ord[A]) + (ord[A] > ord[A + 1]) + (ord[B - 1] > ord[B]) + (B < n && ord[B] > ord[B + 1]) - (B == A + 1 && ord[A] > ord[B]);
        cout << num << "\n";
    }
}