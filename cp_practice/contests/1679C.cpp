#include<bits/stdc++.h>
#define ll int
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

    int n,q; cin >> n >> q;

    multiset<ll> rows[2];
    // set<ll> rows[2];
    // map <ll,ll> done_rows,donw_cols;
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            ll x,y;
            cin >> x >> y;
            rows[0].insert(x);
            rows[1].insert(y);
        }
        if(t==2){
            ll x,y;
            cin >> x >> y;
            rows[0].erase(rows[0].find(x));
            rows[1].erase(rows[1].find(y));
        }
        if(t==3){
            ll x[2][2];
            cin >> x[0][0] >> x[1][0] >> x[0][1] >> x[1][1];
            int i = (x[1][1]-x[1][0])<=(x[0][1]-x[0][0]) ? 1 : 0;
            bool ans = true;
            for(int j = x[i][0]; j<=x[i][1]; j++){
                if(!rows[i].count(j)){
                    ans = false;
                    break;
                }
            }
            bool ans1 = true;
            i = (i+1)%2;
            if(!ans){
            for(int j = x[i][0]; j<=x[i][1]; j++){
                if(!rows[i].count(j)){
                    ans1 = false;
                    break;
                }
            }
            }
            ans || ans1 ? cout << "Yes\n": cout << "No\n";
        }
    }    

    return 0;}