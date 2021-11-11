#include <bits/stdc++.h>
using namespace std;
int n, q, x_1, x_2, y_1, y_2, num[1001][1001];
char forest[1001][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> (forest[i] + 1);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            num[i][j] = num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1] + (forest[i][j] == '*');
        }
    }
    while (q--){
        cin >> y_1 >> x_1 >> y_2 >> x_2;
        y_1--; x_1--;
        cout << (num[y_2][x_2] - num[y_1][x_2] - num[y_2][x_1] + num[y_1][x_1]) << "\n";
    }
}