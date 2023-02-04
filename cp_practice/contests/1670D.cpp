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

// int power(int a, int b, int mod){
//     int ans = 1;
//     while (b > 0){
//         if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
//         a = (a%mod * 1LL * a%mod) % mod;
//         b >>= 1;}
//     return ans%mod;}

// ll modInverse(ll n,ll mod){
//     return power(n,mod-2,mod)%mod;}

deq solve;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);


    int ans = 1,x = 0,y = 2;
    solve.pb(0);
    solve.pb(0);

    while(x<1000000000){
            x+=y;
            ans++;
            // if(x>=n)break;
            solve.pb(x);
            y+=2;
            x+=y;
            ans++;
            // if(x>=n)break;
            solve.pb(x);
            x+=y;
            ans++;
            // if(x>=n)break;
            solve.pb(x);
            y+=2;
        }

        // cout << ans << "\n";

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        if(n==0){
            cout << "0\n";
            continue;
        }

        auto itr = lower_bound(all(solve),n);
        cout << itr - solve.begin() << "\n";

        // cout << ans << "\n";

    }

    return 0;}