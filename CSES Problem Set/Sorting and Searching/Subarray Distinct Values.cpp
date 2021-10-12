#include <bits/stdc++.h>
using namespace std;
int n, k, x[200001];
map<int, int> numToPos;
set<int> pos;
long long num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> x[i];
        if (numToPos.count(x[i])) pos.erase(pos.find(numToPos[x[i]]));
        pos.insert(i);
        numToPos[x[i]] = i;
        
        if (pos.size() > k + 1){
            auto it = pos.begin();
            numToPos.erase(x[*it]);
            pos.erase(it);
        }
        
        if (pos.size() < k + 1) num += i;
        else num += (i - *pos.begin());
    }
    cout << num;
}
