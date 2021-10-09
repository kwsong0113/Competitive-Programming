#include <bits/stdc++.h>
using namespace std;
string s;
char rem = 'Z';
int maxRep, temp;

int main(){
    cin >> s;
    for (char c: s){
        if (c == rem) temp++;
        else {
            rem = c;
            maxRep = max(maxRep, temp);
            temp = 1;
        }
    }
    maxRep = max(maxRep, temp);
    cout << maxRep;
}