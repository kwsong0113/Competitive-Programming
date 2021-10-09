#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    if (n >= 4 || n == 1){
        for (int i = 2; i <= n; i += 2) cout << i << " ";
        for (int i = 1; i <= n; i += 2) cout << i << " ";
    }
    else {
        cout << "NO SOLUTION";
    }
}
