#include <bits/stdc++.h>
using namespace std;
string s;
pair<int, int> now = {1, 1}, dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
map<char, pair<int, int>> dirMap = {{'D', {1, 0}}, {'U', {-1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
int num, visited[9][9];
 
void search(int i){
    if (now == make_pair(7, 1)){
        num += (i == 48);
        return;
    }
    if (!visited[now.first + 1][now.second] && !visited[now.first - 1][now.second] && visited[now.first][now.second + 1] && visited[now.first][now.second - 1]) return;
    if (visited[now.first + 1][now.second] && visited[now.first - 1][now.second] && !visited[now.first][now.second + 1] && !visited[now.first][now.second - 1]) return;
    if (s[i] == '?'){
        for (pair <int, int> move: dir){
            now.first += move.first;
            now.second += move.second;
            if (now.first >= 1 && now.first <= 7 && now.second >= 1 && now.second <= 7 && !visited[now.first][now.second]){
                visited[now.first][now.second] = 1;
                search(i + 1);
                visited[now.first][now.second] = 0;
            }
            now.first -= move.first;
            now.second -= move.second;
        }
    }
    else {
        pair <int, int> move = dirMap[s[i]];
        now.first += move.first;
        now.second += move.second;
        if (now.first >= 1 && now.first <= 7 && now.second >= 1 && now.second <= 7 && !visited[now.first][now.second]){
            visited[now.first][now.second] = 1;
            search(i + 1);
            visited[now.first][now.second] = 0;
        }
        now.first -= move.first;
        now.second -= move.second;
    }
}
 
int main(){
    cin >> s;
    visited[1][1] = 1;
    for (int i = 0; i <= 8; ++i){
        visited[i][0] = visited[0][i] = visited[i][8] = visited[8][i] = 1;
    }
    search(0);
    cout << num;
}

