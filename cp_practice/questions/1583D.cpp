#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

    int n;
    cin >> n;

    int x = 2;
    for(;x <= n; x++){
        cout << "? ";
        rp(j,1,n)cout << 1 << ' ';
        cout << x << endl;
        int y;
        cin >> y;
        if(y==0)break;
    }

    int ans[n+1];
    ans[n] = n+2-x;
    int z = n+2-x;
    rp(i,1,n+1){
        if(i==z)continue;
        int k = i-z+1;
        int h = 0;
        if(k <= 0) h = -k+1;
        cout << "? ";
        rp(i,1,n) cout << 1 + h << ' ';
        cout << k + h << endl;
        int y;
        cin >> y;
        ans[y] = i;
    }

    cout << "! ";
    rp(i,1,n+1)cout << ans[i] << " ";
    cout << endl;

    return 0;}