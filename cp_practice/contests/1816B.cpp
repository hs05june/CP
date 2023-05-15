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

        int ans[2][n];

        int maxi = 2*n, mini = n;

        ans[0][0] = maxi, ans[1][0] = mini;
        ans[0][n-1] = 1, ans[1][n-1] = maxi-1;
        maxi-=2;mini--;
        for(int i = 1; i < n-1; i+=2){
            ans[1][i] = maxi;
            ans[0][i] = mini;
            ans[1][i+1] = mini-1;
            ans[0][i+1] = maxi-1;
            maxi-=2;
            mini-=2;
        }
        
        rp(i,0,n){
            cout << ans[0][i] << " ";
        }
        cout << "\n";
        rp(i,0,n){
            cout << ans[1][i] << " ";
        }
        cout << "\n";
    }

    return 0;}