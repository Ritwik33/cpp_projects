//Binary Search -problem 2 - cf
//link : https://codeforces.com/contest/812/problem/C


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

ll check(ll mid , ll a[], ll n , ll S)
{
    ll taken_number = mid + 1;  //0 based indexing
    vector<ll>v;
    for(ll i=0;i<n;i++)
    {
        ll cost = a[i] + ((i+1) * taken_number);
        v.push_back(cost);
        
    }
    
	sort(v.begin(), v.end());
	ll sum = 0, count = 0;
	for (ll i = 0; i < taken_number; i++) 
	{
		if (sum + v[i] > S) {
			break;
		}
		else {
			sum += v[i];
			count++;
		}
	}

	if (count >= taken_number) {
		return sum;
	}
	else return -1;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    IOS;
    ll n,S;
    cin>>n>>S;
    ll a[n],our_cost=0, total_cost=0,ans=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    ll l=0 ,h =n-1;
    while(l<=h)
    {
        ll mid=(l+h)/2;
        total_cost = check(mid, a, n, S);
        if(total_cost==-1)
        {
            h=mid-1;
            continue;
        }
       else if(total_cost<=S)
       {
           ans=mid+1; //0 based indexing
           our_cost = total_cost;
           l=mid+1;
       }
        else
            h=mid-1;
    }
    
    cout << ans << " " << our_cost << endl;
}
    
