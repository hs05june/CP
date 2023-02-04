//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define lb(a,b,c) lower_bound(a,b,c)
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
const ll M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n],b[n+1];

        for(int i=0;i<n;i++)cin>> a[i];

        b[0] = a[0];
        b[n] = a[n-1];

        for(int i = 1; i <n; i++){
            b[i] = (a[i-1] * a[i])/( __gcd(a[i],a[i-1]));
        }

        // for(int i = 0; i <= n; i++){
        //     cout << b[i] << " ";
        // }
        bool ans = true;
        for(int i = 1; i <= n; i++){
            if(__gcd(b[i],b[i-1])!=a[i-1]){
                ans = false;
                break;
            }
        }

        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;}