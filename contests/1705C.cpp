#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
#define int long long
int M = 1000000007;
using namespace std;

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){
        int n,c,q;
        cin >> n >> c >> q;
        ll siz = n;

        string a;
        cin >> a;

        map<ll,ll> cnt;
        deque<ll> str;

        cnt.insert({0,0});
        str.push_back(0);

        while(c--){
            ll l,r;
            cin >> l >> r;

            str.push_back(n);
            cnt.insert({n,l-1});
            n+=(r-l+1);
        }

        // for(auto i : cnt){
        //     cout << i.first << " = " << i.second << endl;
        // }

        while(q--){
            ll x;
            cin >> x;
            
            x--;
           auto z = *(--upper_bound(all(str),x));
          

        int h = (x-z) + cnt[z];

           while(h>=siz){
            z = *(--upper_bound(all(str),h));
            h = (h-z) + cnt[z];
           }

            cout << a[h] << "\n";
            
            }
    }

    return 0;}