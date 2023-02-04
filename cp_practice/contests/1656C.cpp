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

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        ll n;
        cin >> n;

        deque<ll> a(n,0);
        bool one  = false,zero = false;

        for(ll i = 0; i < n; i++){
            cin >> a[i];
            if(a[i]==1)one=true;
            if(a[i]==0)zero=true;
        }

        bool all_equal = true;

        for(ll i = 1; i < n; i++){
            if(a[i]!=a[0]){
                all_equal=false;
            }
        }

        if(n==1 || all_equal){
            cout << "YES\n";
            continue;
        }

        if(one && zero){
            cout << "NO\n";
            continue;
        }
        
        if(!one){
            cout << "YES\n";
            continue;
        }

        bool ans = true;

        sort(a.begin(), a.end());

        for(int i = 0; i < a.size()-1; i++){
            if(a[i+1]-a[i]==1){
                ans = false;
                break;
            }
        }

        ans  ? cout << "YES\n": cout << "NO\n";
            }

    return 0;}