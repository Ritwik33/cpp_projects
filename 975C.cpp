// Binary Search
//Concepts : Upper_Bound , Binary Search
// link : https://codeforces.com/problemset/problem/975/C


#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    IOS;
        ll n,q;
        cin>>n>>q;
        ll a[n];
        ll prefix[n];
        
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(i==0)
                prefix[i]=a[i];
            else
                prefix[i]=a[i]+prefix[i-1];
        }
        
 
 
        ll arrows=0;
        while(q--)
        {
            ll x;
            cin>>x;
            arrows+=x;
            if(arrows>=prefix[n-1])
                {
                    //everyone gets revived
                    
                    cout<<n<<endl;
                    arrows=0;
                }
            else
            {
                ll uind=upper_bound(prefix,prefix+n,arrows)-prefix;
                cout<<n-uind<<endl;
            }
        }
        return 0;
    }
