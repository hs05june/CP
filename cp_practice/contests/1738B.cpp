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
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
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

    int t; cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;

        int a[n],s[k];

        rp(i,0,k)cin >> s[i];

        if(k==1){
            cout << "YES\n";
            continue;
        }

        for(int i = k-1; i>=1; i--){
            a[n-k+i] = s[i] - s[i-1];
        }        

        ll x = a[n-k+1];

        bool check = true;

        if(k>2){
            for(int i = n-1; i>(n-k+1); i--){
                if(a[i]<a[i-1]){
                    check= false;
                    break;
                }
            }
        }

        // rp(i,0,n){
        //     cout << a[i] << " ";
        // }

        // cout << "\n";

        // cout << x << "\n";

        if(!check){
            cout << "NO\n";
            continue;
        }

        if(s[0]>(x*(n-k+1))){
            cout << "No\n";
        }
        else{
            cout << "YES\n";
        }

    }

    return 0;}