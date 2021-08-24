#include<bits/stdc++.h>
using namespace std;

int main() {
    //fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //vectors are dynamic containers
    //we dont need to know the size in advance
    //elements can be inserted in a vector using the vec.push_back(val) or vec.emplace_back(val) methods
    //elements can be accessed by indexes i.e. vec[i][j]

    // 1-D vector...
    //vector<int> vec
    //vec[i]
    vector<int> vec1;
    vec1.push_back(56);
    vec1.emplace_back(1025);
    vec1.push_back(236);
    for(int i = 0;i<vec1.size();i++) cout<<vec1[i]<<" ";
    cout<<endl<<endl;

    //2-D vector...
    //vector<vector<int>> vec
    //vec[i][j]
    vector<vector<int>> vec2;
    vector<int> vec21(5,2);
    vector<int> vec22(10,3);
    vec2.emplace_back(vec21);
    vec2.push_back(vec22);
    for(int i = 0;i<vec2.size();i++) {
        for(int j = 0;j<vec2[i].size();j++){ 
            cout<<vec2[i][j]<<" ";
        }
        cout<<endl;
    }


    //Sets...
    //Sets stores elements in a sorted fashion
    //stores unique elements
    //cannot be accessed by indices
    //can only be accesed by iterators
    //set<int> st
    //elements are inserted using st.insert(val) method
    //st.begin() points to the first element of set and st.end() points to the next-to-last memory space of set
    //red-black tree is implemented at back
    cout<<endl<<endl;
    set<int> st;
    st.insert(3);//tc of insert method == O(logn)
    st.insert(5);
    st.insert(5);//duplicate
    st.insert(4);
    st.insert(-1);
    st.insert(-2);
    st.insert(-1);//duplicate
    st.insert(-100);
    st.insert(2);
    st.insert(6);
    cout<<st.size()<<endl;
    // set<int>::iterator it = st.begin();
    st.erase(4);//tc of erase method == O(logn)
    st.erase(st.find(-100));
    st.erase(st.find(5),st.end());
    auto itr = st.find(-2);
    st.erase(itr);
    st.insert(10);
    st.insert(15);
    st.insert(25);
    st.insert(100);
    st.insert(13);
    st.insert(55);
    st.erase(st.find(10),st.find(55));// deletes elements in a first included last excluded manner
    for(auto it=st.begin();it!=st.end();it++) cout<<*it<<" ";
    
    return 0;
}