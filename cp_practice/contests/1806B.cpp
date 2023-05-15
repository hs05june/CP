#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
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

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        int cnt0 = 0, cnt1 = 0;
        rp(i,0,n){
            int x;
            cin >> x;
            if(x==0)cnt0++;
            else if(x!=1) cnt1++;
        }
        // deq arr;
        // while(cnt0>0 || cnt1>0){
        //     if(cnt0>0){arr.pb(0);cnt0--;}
        //     if(cnt1>0){arr.pb(1);cnt1--;}
        // }
        if(cnt0<=ceil(float(n)/2)){
            cout << "0\n";
        }
        else if(cnt1!=0 || cnt0==n){
            cout << "1\n";
        }
        else{
            cout << "2\n";
        }
    }

    return 0;}