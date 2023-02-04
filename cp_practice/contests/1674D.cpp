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

        ll b[n] = {0};

        if(n&1){
            b[0] = a[0];
        }

        for(ll i = n-1; i>0;i-=2){
            b[i] = max(a[i],a[i-1]);
            b[i-1] = min(a[i],a[i-1]);
        }

        bool ans = true;

        for(ll i = 0; i < n-1;i++){
            if(b[i]>b[i+1]){
                ans = false;
                break;
            }
        }

        ans ? cout << "YES\n": cout << "NO\n";
    }

    return 0;}