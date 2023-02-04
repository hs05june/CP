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

        ll n,x;
        cin >> n >> x;

        deque<ll> a(n,0);
        ll sum = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }

        ll ans = 0;

        sort(a.begin(), a.end());

        ll preffix[n+1] = {0};

        for(int i = 1; i <= n; i++){
            preffix[i] = a[i-1]+preffix[i-1];
        }

        ll days = 0;

        for(ll i = n; i>0;i--){
            if((x - preffix[i] - (days*i))<0)continue;
            ll z = (x - preffix[i] - (days*i))/i;
            days += (z+1);
            ans+=i*(z+1);
        }
            cout << ans << "\n";
        // cout << ans << "\n";
    }

    return 0;}