#include <bits/stdc++.h>
using namespace std;
string s;
const int INF = INT_MAX;
int n, m, dist[1002][1002];
pair<int, int> parent[1001][1001];
pair<int, int> startPoint;
queue<pair<int, int>> q;
bool possible = false;
vector<char> ans;
 
void check(pair<int, int> x, pair<int, int> y){
    int dist1 = dist[x.first][x.second];
    if (dist1 + 1 < dist[y.first][y.second]){
        dist[y.first][y.second] = dist1 + 1;
        parent[y.first][y.second] = x;
        q.push(y);
    }
}
 
void printPath(pair<int, int> x){
    if (x == startPoint) return;
    pair<int, int> y = parent[x.first][x.second];
    if (x.first > y.first) ans.push_back('D');
    else if (x.first < y.first) ans.push_back('U');
    else if (x.second > y.second) ans.push_back('R');
    else ans.push_back('L');
    printPath(y);
}
 
void bfs(bool opt){
    while (!q.empty()){
        pair<int, int> u = q.front(), v; q.pop();
        if (opt && (u.first == 1 || u.first == n || u.second == 1 || u.second == m)){
            possible = true;
            printPath(u);
            return;
        }
        v = u; v.first++; check(u, v);
        v = u; v.first--; check(u, v);
        v = u; v.second++; check(u, v);
        v = u; v.second--; check(u, v);
    }
}
 
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> s;
        for (int j = 1; j <= m; ++j){
            dist[i][j] = INF;
            if (s[j - 1] == '#') dist[i][j] = 0;
            else if (s[j - 1] == 'M'){
                q.push({i, j}); dist[i][j] = 0;
            }
            else if (s[j - 1] == 'A'){
                startPoint = {i, j};
            }
        }
    }
    bfs(false);
    dist[startPoint.first][startPoint.second] = 0;
    parent[startPoint.first][startPoint.second] = startPoint;
    q.push(startPoint);
    bfs(true);
    if (possible){
        reverse(ans.begin(), ans.end());
        cout << "YES\n" << ans.size() << "\n";
        for (char c: ans) cout << c;
    }
    else cout << "NO";
}