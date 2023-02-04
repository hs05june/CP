#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);cout.tie(0);
#define HARPREET cout << fixed << setprecision(20);
int M = 1000000007;
using namespace std;

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        ll n;
        cin >> n;

        map<ll,ll> distinct;

        for(int i = 0 ; i < n ; i++){
            ll x;
            cin >> x;
            distinct[x]++;
        }

        ll two = 0, ones = 0;

        for(auto i : distinct){
            if(i.second >= 2)two++;
            else if(i.second==1)ones++;
        }

        cout << two + (ull)ceil((double)ones/2) << "\n";
    }

    return 0;}