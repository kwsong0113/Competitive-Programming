#include <bits/stdc++.h>
using namespace std;
pair<int, int> delta[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int t, n, m, lx, ly;
string grid[1000001];

bool freeCell(string grid[], int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.');
}

int numFreeNeigbors(string grid[], int x, int y){
    int num = 0;
    for (auto [dx, dy]: delta){
        if (freeCell(grid, x + dx, y + dy)) num ++;
    }
    return num;
}

void dfs(string grid[], int x, int y){
    for (auto [dx, dy]: delta){
        if (freeCell(grid, x + dx, y + dy) && numFreeNeigbors(grid, x + dx, y + dy) <= 1){
            grid[x + dx][y + dy] = '+';
            dfs(grid, x + dx, y + dy);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> grid[i];
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 'L'){
                    lx = i; ly = j; break;
                }
            }
        }
        dfs(grid, lx, ly);
        for (int i = 0; i < n; ++i){
            cout << grid[i] << "\n";
        }
    }
}
