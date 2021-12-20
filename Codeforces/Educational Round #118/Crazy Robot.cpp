#include <bits/stdc++.h>
using namespace std;
pair<int, int> delta[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int t, n, m, lx, ly;

bool freeCell(char **grid, int x, int y){
    return (x >= 1 && x <= n && y >= 1 && y <= m && grid[x][y] == '.');
}

int numFreeNeigbors(char **grid, int x, int y){
    int num = 0;
    for (auto [dx, dy]: delta){
        if (freeCell(grid, x + dx, y + dy)) num ++;
    }
    return num;
}

void dfs(char **grid, int x, int y){
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
        char **grid;
        grid = new char *[n + 1];
        for (int i = 0; i <= n; ++i) grid[i] = new char[m + 1];
        for (int i = 1; i <= n; ++i) cin >> (grid[i] + 1);
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                if (grid[i][j] == 'L'){
                    lx = i; ly = j; break;
                }
            }
        }
        dfs(grid, lx, ly);
        for (int i = 1; i <= n; ++i){
            cout << (grid[i] + 1) << "\n";
        }
    }
}