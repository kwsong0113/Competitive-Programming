#include <bits/stdc++.h>
using namespace std;
int n, a, b, num, maxNum;
vector<pair<int, int>> customer;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b;
        customer.push_back({a, 1});
        customer.push_back({b, -1});
    }
    sort(customer.begin(), customer.end());
    for (pair<int, int> x: customer){
        num += x.second;
        maxNum = max(maxNum, num);
    }
    cout << maxNum;
}