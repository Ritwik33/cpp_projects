#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec;
    vector<int> vec1;
    for(int i = 0;i<n;i++) {
        vector<int> vec2(i+1);
        for(int j = 0;j<vec2.size();j++) {
            if(j == 0 || j == vec2.size() - 1) {
                vec2[j] = 1;
            }
            else{
                vec2[j] = vec1[j] + vec1[j-1];
            }
        }
        vec.push_back(vec2);
        vec1 = vec2;
    }
    for(int i = 0;i<vec.size();i++) {
        for(int j = 0;j<vec[i].size();j++) cout << vec[i][j] << " ";
        cout << "\n";
    }
    return 0;
}