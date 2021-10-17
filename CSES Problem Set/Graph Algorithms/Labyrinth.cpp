#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> start, endPoint, u, v;
char labyrinth[1001][1001];
int dist[1001][1001];
map <pair<int, int>, pair<int, int>> parent;
queue<pair<int, int>> q;
map<pair<int, int>, char> delta = {{{1, 0}, 'D'}, {{0, 1}, 'R'}, {{-1, 0}, 'U'}, {{0, -1}, 'L'}};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> (labyrinth[i] + 1);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (labyrinth[i][j] == 'A') start = {i, j};
            else if (labyrinth[i][j] == 'B') endPoint = {i, j};
        }
    }
    q.push(start);
    labyrinth[start.first][start.second] = '#';  
    parent[start] = start;
    while (!q.empty()){
        u = q.front(); q.pop();
        for (auto w: delta){
            auto d = w.first;
            v = {u.first + d.first, u.second + d.second};
            if (v.first >= 1 && v.first <= n && v.second >= 1 && v.second <= m){
                if (labyrinth[v.first][v.second] != '#'){
                    labyrinth[v.first][v.second] = '#';
                    dist[v.first][v.second] = dist[u.first][u.second] + 1;
                    q.push(v);
                    parent[v] = u;
                }
            }
        }
    }
    if (!parent.count(endPoint)){
        cout << "NO"; 
    }
    else {
        cout << "YES\n" << dist[endPoint.first][endPoint.second] << "\n";
        vector<char> path;
        while (parent[endPoint] != endPoint){
            path.push_back(delta[{endPoint.first - parent[endPoint].first, endPoint.second - parent[endPoint].second}]);
            endPoint = parent[endPoint];
        }
        reverse(path.begin(), path.end());
        for (char c: path) cout << c;
    }
}