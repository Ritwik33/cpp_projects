#include<bits/stdc++.h>
using namespace std;
#define vi                                                         vector<int>
#define vi2                                                        vector<vector<int>>
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

char board[9][9];

bool isValid(char val, int row, int col) {
    rep(i, 0, 9) {
        if(board[row][i] == val) return false;
        if(board[i][col] == val) return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false;
    }
    return true;
}

bool solve() {
    rep(row, 0, 9) {
        rep(col, 0, 9) {
            if(board[row][col] == '.') {
                for(char val = '1';val<='9';val++) {
                    if(isValid(val, row, col)) {
                        board[row][col] = val;
                        if(solve()) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    FIO;
    rep(i, 0, 9) {
        rep(j, 0, 9) cin >> board[i][j];
    }
    solve();
    rep(i, 0, 9) {
        rep(j, 0, 9) {
            cout << board[i][j];
            j == 2 || j == 5 ? cout << "  ":cout << " ";
        }
        i == 2 || i == 5 ? cout << "\n\n" : cout << "\n";
    }
    return 0;
}