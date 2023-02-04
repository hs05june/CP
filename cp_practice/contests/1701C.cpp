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
        map<ll,ll> prof_task;

        for(int i = 1; i <= n; i++){
            prof_task.insert({i,0});
        }

        for(ll i = 0; i < m; i++){
            ll x;
            cin >> x;
            prof_task[x]++;
        }

        multiset<ll> s;

        for(auto i : prof_task){
            s.insert(i.second);
        }

        ll x = *(--s.end()),y=*(s.begin());
        while(x-1>=y+2){
            s.erase(s.begin());
            s.erase((--s.end()));
            s.insert(x-1);
            s.insert(y+2);
            x = *(--s.end());
            y = *(s.begin());
        }

        cout << *(--s.end()) << "\n";
    }

    return 0;}