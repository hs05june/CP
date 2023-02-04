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
int M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

int main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;

        ll a[n];

        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }

        deque<pair<ll, ll>> ans;

        for(ll i = 1; i < n; i++){
             if(2*a[i] > a[i-1]){
                pair<ll,ll> p;
                ll x = i-1,y;
                while(i<n && (2*a[i]) > a[i-1]){
                    ++i;
                }
                y = i-1;
                ans.push_back({x,y});
             }
        }

        ll cnt = 0;
        for(auto i : ans){
            // cout << "{"<<i.first<<" "<<i.second<<"} ";
            ll z = i.second - i.first+1;
            cnt += (z-k)>0 ? z-k : 0;
        }
        cout << cnt << "\n";
    }

    return 0;}