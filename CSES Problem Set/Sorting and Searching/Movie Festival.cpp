#include <bits/stdc++.h>
using namespace std;
int n, a, b, num;
vector<pair<int, int>> movie;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b;
        movie.push_back({b, a});
    }
    sort(movie.begin(), movie.end());
    int endTime = 0;
    for (pair<int, int> x: movie){
        if (x.second >= endTime){
            num++;
            endTime = x.first;
        }
    }
    cout << num;
}