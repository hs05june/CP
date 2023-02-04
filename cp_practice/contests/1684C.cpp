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

        ll a[n][m],b[n][m];

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
            sort(b[i],b[i]+m);
        }

        bool check = true,already = true;
        deque<pair<ll,ll>> ans;

        for(ll i = 0; i < n; i++){
            deque<ll> d;
            for(ll j = 0; j < m; j++){
                if(a[i][j]!=b[i][j]){
                    d.push_back(j);
                    already = false;
                }
            }
            if(d.size()>=3){
                check = false;
                break;
            }
            if(d.size()==2){
                ans.push_back({d[0],d[1]});
                break;
            }
        }

        if(already){
            cout << "1 1\n";
            continue;
        }

        if(!check){
            cout << "-1\n";
            continue;
        }

        ll x = ans[0].first, y = ans[0].second;
        for(int i = 0; i < n; i++){
            swap(a[i][x],a[i][y]);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j]!=b[i][j]){
                    check = false;
                    break;
                }
            }
            if(!check)break;
        }

        check ? cout << ans[0].first + 1 << " " << ans[0].second + 1 << "\n" :cout <<"-1\n";

    }

    return 0;}