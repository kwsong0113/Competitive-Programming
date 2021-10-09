#include <bits/stdc++.h>
using namespace std;
int n;

void hanoi(int m, int left, int mid, int right){
    if (!m) return;
    hanoi(m - 1, left, right, mid);
    cout << left << " " << right << "\n";
    hanoi(m - 1, mid, left, right);
}

int main(){
    cin >> n;
    cout << ((1 << n) - 1) << "\n";
    hanoi(n, 1, 2, 3);
}