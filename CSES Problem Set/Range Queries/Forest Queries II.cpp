#include <bits/stdc++.h>
using namespace std;

int n, q, opt, y_1, x_1, y_2, x_2, tree[1001][1001], forest[1001][1001];
char c;

void update(int y, int x, int val){
    for (; y <= n; y += y & -y){
        for (int i = x; i <= n; i += i & -i){
            tree[y][i] += val;
        }
    }
}

int query(int y_1, int x_1, int y_2, int x_2){
    int ans = 0;
    for (int i = y_2; i; i -= i & -i){
        for (int j = x_2; j; j -= j & -j){
            ans += tree[i][j];
        }
    }
    for (int i = y_1 - 1; i; i -= i & -i){
        for (int j = x_2; j; j-= j & -j){
            ans -= tree[i][j];
        }
    }
    for (int i = y_2; i; i -= i & -i){
        for (int j = x_1 - 1; j; j-= j & -j){
            ans -= tree[i][j];
        }
    }
    for (int i = y_1 - 1; i; i -= i & -i){
        for (int j = x_1 - 1; j; j-= j & -j){
            ans += tree[i][j];
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> c;
            if (c == '*'){
                update(i, j, 1);
                forest[i][j] = 1;
            }
            else {
                forest[i][j] = -1;
            }
                
        }
    }
    
    while (q--){
        cin >> opt;
        if (opt == 1){
            cin >> y_1 >> x_1;
            update(y_1, x_1, -forest[y_1][x_1]);
            forest[y_1][x_1] = -forest[y_1][x_1];
        }
        else {
            cin >> y_1 >> x_1 >> y_2 >> x_2;
            cout << query(y_1, x_1, y_2, x_2) << "\n";
        }
    }
}