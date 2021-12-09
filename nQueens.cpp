#include<bits/stdc++.h>
using namespace std;
#define vi                                                         vector<int>
#define vi2                                                        vector<vector<int>>
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define int                                                        long long
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void show(vector<vector<char>>& board, int n) {
    rep(i, 0, n) {
        rep(j, 0, n) cout << board[i][j] << " ";
        cout << "\n";
    }
}

bool isPossible(int row, int col, vector<bool>& rowhash, vector<bool>& udHash, vector<bool>& ldHash, int n) {
    if(rowhash[row] || udHash[n-1+row-col] || ldHash[row+col]) return false;
    return true;
}

bool solve(int col, vector<vector<char>>& board, vector<bool>& rowHash, vector<bool>& udHash, vector<bool>& ldHash, int n) {
    if(col == n) {
        show(board, n);
        return true;
    }
    rep(row, 0, n) {
        if(isPossible(row, col, rowHash, udHash, ldHash, n)) {
            board[row][col] = 'Q';
            rowHash[row] = ldHash[row+col] = udHash[n-1+row-col] = true;
            if(solve(col+1, board, rowHash, udHash, ldHash, n)) return true;
            rowHash[row] = ldHash[row+col] = udHash[n-1+row-col] = false;
            board[row][col] = '.';
        }
    }
    return false;
}

signed main() {
    FIO;
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<bool> rowHash(n, false);
    vector<bool> udHash(n, false);
    vector<bool> ldHash(n, false);
    solve(0, board, rowHash, udHash, ldHash, n);
    return 0;
}