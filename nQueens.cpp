#include<bits/stdc++.h>
using namespace std;

bool isValid(int n, int row, int col, vector<char>& rowHash, vector<char>& udHash, vector<char>& ldHash) {
    if(rowHash[row]=='Q' || udHash[n-1+row-col]=='Q' || ldHash[row+col]=='Q') return false;
    return true;
}

bool nQueens(int col, int n, vector<vector<char>>& chess, vector<char>& rowHash, vector<char>& udHash, vector<char>& ldHash) {
    if(col == n) {
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) cout << chess[i][j] << "  ";
            cout << "\n\n";
        }
        return true;
    }
    for(int row = 0;row<n;row++) {
        if(isValid(n, row, col, rowHash, udHash, ldHash)) {
            chess[row][col] = 'Q';
            rowHash[row] = 'Q';
            udHash[n-1+row-col] = 'Q';
            ldHash[row+col] = 'Q';
            if(nQueens(col+1, n, chess, rowHash, udHash, ldHash)==true) return true;
            chess[row][col] = '.';
            rowHash[row] = '.';
            udHash[n-1+row-col] = '.';
            ldHash[row+col] = '.';
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<char>> chess(n, vector<char>(n, '.'));
    vector<char> rowHash(n, '.');
    vector<char> udHash(2*n-1, '.');
    vector<char> ldHash(2*n-1, '.');
    nQueens(0, n, chess, rowHash, udHash, ldHash);
    return 0;
}