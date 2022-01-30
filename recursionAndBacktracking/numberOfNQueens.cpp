#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, vector<char>& rowHash, vector<char>& ldHash, vector<char>& udHash) {
    if(rowHash[row] == 'Q' || ldHash[row+col] == 'Q' || udHash[n-1+row-col] == 'Q') return false;
    return true;
}

int solve(int col, int count, int n, vector<vector<char>>& chess, vector<char>& rowHash, vector<char>& ldHash, vector<char>& udHash) {
    if(col == n) {
        return (count+1);
    }
    for(int row = 0;row<n;row++) {
        if(isValid(row, col, n, rowHash, ldHash, udHash)) {
            chess[row][col] = 'Q';
            rowHash[row] = 'Q';
            ldHash[row+col] = 'Q';
            udHash[n-1+row-col] = 'Q';
            count = solve(col+1, count, n, chess, rowHash, ldHash, udHash);
            chess[row][col] = '.';
            rowHash[row] = '.';
            ldHash[row+col] = '.';
            udHash[n-1+row-col] = '.';
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> chess(n, vector<char>(n, '.'));
    vector<char> rowHash(n, '.');    
    vector<char> ldHash(2*n - 1, '.');    
    vector<char> udHash(2*n - 1, '.');
    cout << solve(0, 0, n, chess, rowHash, ldHash, udHash);
    return 0;
}