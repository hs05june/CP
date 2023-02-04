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

        int n;
        cin >> n;

        ll a[n];

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int m;
        cin >> m;

        deque<ll> b;

        for(int i = 0; i < m; i++){
            ll x;
            cin >> x;
            if(x>0){b.push_back(x);}
        }

        ll preffor[n+2] = {0},prefback[n+2] = {0};

        for(int i = 1; i <= n; i++){
            preffor[i] = preffor[i-1] + a[i-1];
        }
        for(int i = n; i >= 1; i--){
            prefback[i] = prefback[i+1] + a[i-1];
        }

        // for(int i = 0; i <= n+1; i++){
        //     cout << preffor[i] << " ";
        // }
        // cout<<"\n";
        // for(int i = 0; i <= n+1; i++){
        //     cout << prefback[i] << " ";
        // }
        // cout<<"\n";

        ll maxi = 0;

        for(int i = 1; i<=n; i++){
            maxi = max(maxi,preffor[i]);
            maxi = max(maxi,prefback[i]);
        }

        for(int i = 0; i < b.size(); i++){
            maxi+=b[i];
        }

        ll maxi2 = 0;

        // for(int i = 1; i<=n; i++){
        //     maxi2 =max()
        // }

        cout << maxi << "\n";

    }

    return 0;}