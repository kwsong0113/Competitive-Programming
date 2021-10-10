#include <bits/stdc++.h>
using namespace std;
char board[8][8];
vector<int> freeSquare[8];
int num, col[8], diag1[17], diag2[17];

void search(int i){
    if (i == 8){
        num++; return;
    }
    for (int j: freeSquare[i]){
        if (col[j] || diag1[i + j] || diag2[i - j + 8]) continue;
        col[j] = diag1[i + j] = diag2[i - j + 8] = 1;
        search(i + 1);
        col[j] = diag1[i + j] = diag2[i - j + 8] = 0;
    }
}

int main(){
     for (int i = 0; i < 8; ++i){
         cin >> board[i];
         for (int j = 0; j < 8; ++j){
             if (board[i][j] == '.') freeSquare[i].push_back(j);
         }
     }
     search(0);
     cout << num;
}