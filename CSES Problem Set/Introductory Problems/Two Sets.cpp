#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    if (n % 4 == 0){
        cout << "YES\n" << n / 2 << "\n";
        for (int i = 1; i <= n / 4; ++i) cout << 4 * i - 3 << " " << 4 * i << " ";
        cout << "\n" << n / 2 << "\n";
        for (int i = 1; i <= n / 4; ++i) cout << 4 * i - 2 << " " << 4 * i - 1 << " ";
    }
    else if (n % 4 == 3){
        cout << "YES\n" << n / 2 + 1 << "\n";
        for (int i = 1; i <= (n + 1)/ 4; ++i) cout << 4 * i - 3 << " " << 4 * i - 2 << " ";
        cout << "\n" << n / 2 << "\n" << 3 << " ";
        for (int i = 1; i <= n / 4; ++i) cout << 4 * i << " " << 4 * i + 3 << " ";
    }
    else {
        cout << "NO\n";
    }
}