#include<bits/stdc++.h>
using namespace std;

void mult(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    vector<vector<int>> clone(mat1.size(), vector<int>(mat1[0].size()));
    for(int i = 0;i<mat1.size();i++) {
        for(int j = 0;j<mat2[0].size();j++) {
            int temp = 0;
            for(int k = 0;k<mat1[0].size();k++) {
                temp += mat1[i][k]*mat2[k][j];
            }
            clone[i][j] = temp;
        }
    }
    for(int i = 0;i<clone.size();i++) {
        for(int j = 0;j<clone[i].size();j++) mat1[i][j] = clone[i][j];
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<int>> base = {{1, 1}, {1, 0}};
    vector<vector<int>> ans = {{1, 0}, {0, 1}};
    n--;
    while(n>0) {
        if(n%2 == 0) {
            mult(base, base);
            n /= 2;
        } else if(n%2 != 0) {
            mult(ans, base);
            n -= 1;
        }
    }
    cout << "The fibonacci number is: " << ans[0][0];
    return 0;
}