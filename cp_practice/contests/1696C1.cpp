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

        ll n,m;
        cin >> n >> m;

        ll a[n];

        for(ll i = 0; i < n; i++)cin >> a[i];

        ll k;
        cin >> k;

        ll b[k];
        for(ll i = 0; i < k; i++)cin >> b[i];

        deque<pair<ll,pair<ll,ll>>> fir,sec;

        ll z = a[0],cnt = 1;

        while(z%m==0){
            z/=m;
            cnt*=m;
        }
        fir.push_back({z,{0,cnt-1}});
        for(int i = 1; i < n; i++){
            z = a[i],cnt = 1;

            while(z%m==0){
                z/=m;
                cnt*=m;
            }

            ll h = fir.size()-1;
            
            if(fir[h].first==z){
                fir[h].second.second += cnt;
            }
            else{
                fir.push_back({z,{fir[h].second.second+1,fir[h].second.second+cnt}});
            }
        }
        z = b[0],cnt = 1;

        while(z%m==0){
            z/=m;
            cnt*=m;
        }
        sec.push_back({z,{0,cnt-1}});
        for(int i = 1; i < k; i++){
            z = b[i],cnt = 1;

            while(z%m==0){
                z/=m;
                cnt*=m;
            }

            ll h = sec.size()-1;

            if(sec[h].first==z){
                sec[h].second.second += cnt;
            }
            else{
                sec.push_back({z,{sec[h].second.second+1,sec[h].second.second+cnt}});
            }
        }

        // for(int i = 0; i < fir.size();i++){
        //     cout << fir[i].first << " " << fir[i].second.first << " " << fir[i].second.second << endl;
        // }

        // cout << endl;
        // for(int i = 0; i < sec.size();i++){
        //     cout << sec[i].first << " " << sec[i].second.first << " " << sec[i].second.second << endl;
        // }
        
    }

    return 0;}