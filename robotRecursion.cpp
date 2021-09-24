#include<bits/stdc++.h>
using namespace std;

int count(int i, int j, int row, int col) {
    if(i == row-1 && j == col-1) return 1;
    if(i >= row || j >= col) return 0;
    int right = count(i, j+1, row, col);
    int down = count(i+1, j, row, col);
    return right + down;
}

int main() {
    int row, col;
    cin >> row >> col;
    cout << count(0, 0, row, col);
    return 0;
}