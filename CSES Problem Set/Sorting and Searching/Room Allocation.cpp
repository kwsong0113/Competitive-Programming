#include <bits/stdc++.h>
using namespace std;
int n, a, b, k, roomNum[200001];
set<int> room;
pair<int, int> x[400001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b;
        x[2 * i - 1] = {a, -i};
        x[2 * i] = {b, i};
    }
    sort(x + 1, x + 2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i){
        if (x[i].second > 0){
            room.insert(roomNum[x[i].second]);
        }
        else {
            if (room.empty()){
                k += 1; roomNum[-x[i].second] = k;
            }
            else {
                roomNum[-x[i].second] = *(room.begin());
                room.erase(room.begin());
            }
        }
    }
    cout << k << "\n";
    for (int i = 1; i <= n; ++i) cout << roomNum[i] << " ";
}