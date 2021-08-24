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

    //array-whose data type is a vector
    vector<int> vec[4];// it is an array whose data type is a vector, it will contain vectors in its cells
    vec[0].push_back(22);// every index can store a vector
    vec[0].push_back(23);// similarly we can do in case of a set set<int> st[size], array whose each index contains a set....
    vec[1].push_back(105);
    vec[1].push_back(154);
    vec[1].push_back(213);
    vec[2].push_back(45);
    vec[3].push_back(65);
    vec[3].push_back(115);
    cout<<endl<<endl;
    for(int i = 0;i<=3;i++) {
        for(int j = 0;j<vec[i].size();j++) cout<<vec[i][j]<<" ";
        cout<<"\n";
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
    for(auto it:st) cout<<it<<" ";

    //unordered set
    //replica of set only it does not store elements in sorted fashion
    //O(1) in all cases
    //O(n) in very very very rare cases
    //if program does not need sorted elements but only needs unique elements then always use unsorted sets
    unordered_set<int> stu;
    stu.insert(1);
    stu.insert(1);
    stu.insert(15);
    stu.insert(65);
    stu.insert(100);
    cout<<endl<<endl;
    for(auto it:stu) cout<<it<<" ";//for-each loop-constrct

    //multiset...
    //stores all elements, in sorted order with a complexity of O(logn)
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(22);
    ms.insert(45);
    ms.insert(22);
    ms.insert(-100);
    cout<<endl<<endl;
    for(auto it:ms) cout<<it<<" ";
    cout<<endl<<ms.count(22)<<endl;
    cout<<ms.count(1)<<endl;
    cout<<ms.count(100)<<endl;
    //ms.find(val) always points to the first occurence of val
    ms.erase(1);//deletes all occurences of 1
    ms.erase(ms.find(22));// erases the first occurence of 22
    ms.insert(45);
    ms.insert(45);
    ms.insert(45);
    for(auto it:ms) cout<<it<<" ";
    cout<<endl<<ms.empty()<<endl;// returns 1 if multiset is empty and 0 otherwise

    // Map
    // if you want to store key-value pairs then use Map
    // stores unique keys only, in a sorted fashion of keys
    // O(logn) throughout...
    map<int,string> mpp;
    mpp[1] = "Ritwik";
    mpp[2] = "Rishi";
    mpp[4] = "Mayank";
    mpp[5] = "Manas";
    mpp[3] = "Saurav";
    mpp[2] = "rs";// this value takes over...
    for(auto it:mpp) cout<<it.first<<" "<<it.second<<endl;

    //unordered map
    // replica of map, but not sorted keys....
    unordered_map<int,int> mpp1;// used when only uniqueness is desired and sorted keys are not required....

    //multi map
    // stores all elements, but keys are sorted
    multimap<int,int> mpp2;// rarely used...

    queue<int> q;// FIFO data-structure...
    q.push(2);// adds an element to the last position of the queue...
    q.push(3);
    q.push(5);
    q.pop();// deletes the first element in the queue...








    return 0;
}