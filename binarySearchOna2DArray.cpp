#include<bits/stdc++.h>
using namespace std;

void search(vector<vector<int>>& mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();
    int count = rows*cols;
    int low, high;
    low = 0;
    high = count-1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        int row, col;
        row = mid%cols;
        col = mid/cols;
        if(mat[row][col] == target) {
            cout << row << " " << col;
            return;
        } else if(target < mat[row][col]) high = mid-1;
        else low = mid+1;
    }
    return;
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> mat(row, vector<int>(col));
    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) cin >> mat[i][j];
    }
    int target;
    cin >> target;
    search(mat, target);
    return 0;
}