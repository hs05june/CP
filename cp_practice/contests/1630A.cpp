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

    int t; cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;

        int used[n] = {0};
        deque<pii> ans;

        if(n==4 && k==3){
            cout << "-1\n";
            continue;
        }

        if(k!=n-1){
            ans.pb({k,n-1});
            used[k]=1;
            used[n-1]=1;}
        else{
            ans.pb({n-2,n-1});
            ans.pb({1,n-3});
            used[n-2] = 1;
            used[1] = 1;
            used[n-3] = 1;
            used[n-1] = 1;
        }
            for(int i = n-1; i>=0;i--){
                if(used[i]==0){
                    ll z = n-1-i;
                    if(used[z]==0){
                        ans.pb({z,i});
                        used[z] = 1;
                        used[i] = 1;
                    }
                    else{
                        used[0] = 1;
                        used[i] = 1;
                        ans.pb({0,i});
                    }
                }
            }
                rp(i,0,sz(ans)){
                    cout << ans[i].f << " " << ans[i].s << "\n";
                }

    }

    return 0;}