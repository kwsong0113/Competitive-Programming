#include <bits/stdc++.h>
using namespace std;
int n, m, numRoom;
char building[1001][1001];

void dfs(int x, int y){
    if (x > n || x < 1 || y > m || y < 1) return;
    if (building[x][y] == '#') return;
    building[x][y] = '#';
    dfs(x + 1, y); dfs(x - 1, y); dfs(x, y + 1); dfs(x, y - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> (building[i] + 1);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (building[i][j] == '.'){
                dfs(i, j); numRoom += 1;
            }
        }
    }
    cout << numRoom;
}
