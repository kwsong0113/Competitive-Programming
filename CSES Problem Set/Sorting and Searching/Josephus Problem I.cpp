#include <bits/stdc++.h>
using namespace std;
int n;

void search(int l, int r, int delta, int op){
    if (l == r){
        cout << l; return;
    }
    for (int i = l + delta * op; i <= r; i += 2 * delta) cout << i << " ";
    int num = (r - l) / delta + 1;
    num = (num & 1) ^ op;
    search(l + delta - delta * op, r - delta * num, 2 * delta, num);
}

int main(){
    cin >> n;
    search(1, n, 1, 1);
}