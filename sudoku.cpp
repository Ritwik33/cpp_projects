#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for(int i = 0;i<9;i++) {
        if(board[row][i] == c) return false;
        if(board[i][col] == c) return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board) {
    for(int row = 0;row<9;row++) {
        for(int col = 0;col<9;col++) {
            if(board[row][col] == '.') {
                for(char c = '1';c<='9';c++) {
                    if(isValid(board, row, col, c)) {
                        board[row][col] = c;
                        if(solve(board)) return true;
                        else board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void disp(vector<vector<char>>& board) {
    for(int i = 0;i<9;i++) {
        for(int j = 0;j<9;j++) {
            if(j == 3 || j == 6) cout << "  ";
            cout << board[i][j] << "  ";
        }
        if(i==2 || i==5) cout << "\n\n";
        cout << "\n\n";
    }
}

int main() {
    vector<vector<char>> board(9, vector<char>(9, '.'));
    cout << "Please Enter a valid sudoku board:\n";
    for(int i = 0;i<9;i++) {
        for(int j = 0;j<9;j++) cin >> board[i][j];
    }
    solve(board);
    cout << "\n\nThe solution of the board is:\n\n";
    disp(board);
    return 0;
}