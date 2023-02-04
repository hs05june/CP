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

        ll a[n];

        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }

        ll sum = 0;
        bool ans = true,zero = false;

        for(ll i = 0; i< n; i++){
            sum+=a[i];
            if(sum<0){
                ans = false;
                break;
            }
            else if(sum == 0 && !zero){
                zero = true;
            }
            else if(sum != 0 && zero){
                ans = false;
                break;
            }
        }

        if(sum!=0)ans=false;

        ans ? cout << "YES\n": cout << "NO\n";

    }

    return 0;}