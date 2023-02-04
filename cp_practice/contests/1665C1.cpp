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

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        mii parent;

        rp(i,1,n){
            int x;
            cin >> x;
            parent[x]++;
        }

        deq cnt;

        cnt.pb(1);
        for(auto i : parent){
            cnt.pb(i.s);
        }

        sort(cnt.begin(),cnt.end());
        reverse(cnt.begin(),cnt.end());

        deq remain;
        int ans = cnt.size(),x = cnt.size();

        for(auto i : cnt){
            int y = i<=x ? 0 : (i-x);
            --x;
            remain.pb(y);
        }

        int y = 0, sum = 0, i = 0;

        while(i<sz(remain) && y<=remain[i]){
            sum+=remain[i];
            y = (sum%(i+2))==0 ? (sum/(i+2)) : (sum/(i+2)) + 1;
            ++i;
        }

        cout << ans + y << "\n";

    }

    return 0;}