#include <bits/stdc++.h>
using namespace std;
int n, k, a, b, num;
pair<int, int> movie[200001];
multiset<int> endTime;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b;
        movie[i] = {b, a};
    }
    sort(movie + 1, movie + n + 1);
    for (int i = 1; i <= k; ++i) endTime.insert(1);
    
    for (int i = 1; i <= n; ++i){
        auto it = endTime.upper_bound(movie[i].second);
        if (it == endTime.begin()) continue;
        it--; num++;
        endTime.erase(it); endTime.insert(movie[i].first);
    }
    cout << num;
}