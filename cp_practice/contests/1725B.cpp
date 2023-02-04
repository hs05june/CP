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

int main(){
    CODE BY HARPREET

    ll n,d;
    cin >> n >> d;

    deque<ll> p;

    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        p.push_back(x);
    }

    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    ll ans = 0, remain = n;

    for(int i = 0; i < p.size(); i++){
        ll z = (d / p[i]) + 1;
        if(z>remain)break;
        else{
            remain -= z;
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;}