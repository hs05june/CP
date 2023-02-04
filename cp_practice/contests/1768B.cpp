#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;
        vector<ll> arr;

        int check = 0;

        mii cnt;

        rp(i,0,n){
            int x;
            cin >> x;
            arr.pb(x);
            cnt[arr[i]] = i;
            if(arr[i]>i)check = arr[i];
        }

        int x = cnt[1];

        for(auto i : cnt){
            if(i.s<x){
                check = i.f-1;
                break;
            }
            x = i.s;
        }

        cout << (int)(ceil(((float)n-check)/k)) << "\n";
        // cout << ((n-check)/k) << "\n";
    }

    return 0;}  