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
    
        ll set_bits[31] = {0};

        ll n,k;
        cin >> n >> k;

        for(ll i = 0 ; i <  n ; i++){
            ll x;
            cin >> x;
            for(int j = 0; j <=30 && (1<<j)<=x;j++){
                if(((1<<j)&x)!=0)set_bits[j]++;
            }
        }

        ll ans = 0;

        for(int i = 30; i>=0; i--){
            if(k>=(n-set_bits[i])){
                k-=(n-set_bits[i]);
                ans+=(1<<i);
            }
        }

        cout << ans << "\n";

    }

    return 0;}