#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, q, a, b, p[N], tree[2 * N];
char opt;
vector<int> salaries;
vector<array<int, 3>> queries;

void update(int k, int val){
    while (k <= 2 * N){
        tree[k] += val;
        k += k & -k;
    }
}

int sum(int k){
    int s = 0;
    while (k >= 1){
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

int query(int x){
    int ind = upper_bound(salaries.begin(), salaries.end(), x) - salaries.begin();
    return sum(ind);
}

void add(int x, int delta){
    int ind = upper_bound(salaries.begin(), salaries.end(), x) - salaries.begin();
    update(ind, delta);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> p[i]; salaries.push_back(p[i]);
    }
    while (q--){
        cin >> opt >> a >> b;
        queries.push_back({opt == '!', a, b});
        if (opt == '!') salaries.push_back(b);
    }
    sort(salaries.begin(), salaries.end());
    salaries.erase(unique(salaries.begin(), salaries.end()), salaries.end());
    for (int i = 1; i <= n; ++i){
        add(p[i], 1);
    }
    
    for (auto u: queries){
        if (u[0] == 1){
            add(p[u[1]], -1);
            p[u[1]] = u[2];
            add(p[u[1]], 1);
        }
        else {
            cout << (query(u[2]) - query(u[1] - 1)) << "\n";
        }
    }
}