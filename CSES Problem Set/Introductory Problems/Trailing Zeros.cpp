#include <bits/stdc++.h>
using namespace std;
int n, sum;

int main(){
    cin >> n;
    while (n){
        n /= 5;
        sum += n;
    }
    cout << sum;
}