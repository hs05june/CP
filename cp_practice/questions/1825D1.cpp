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

deq graph[200007];
int Size[200007];

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

int dfs(int n, int parent){
    int ans = 1;
    for(auto i : graph[n]){
        if(i == parent)continue;
        ans += dfs(i,n);
    }
    return Size[n] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;

    rp(i,1,n){
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    if(k & 1){
        cout << "1\n";
        return 0;
    }

    int x = dfs(1,0);

    int ans = 0;

    rp(i,1,n+1){
        ans = ans%M + (((Size[i])%M*(n-Size[i])%M)%M)%M;
    }

    ans = (ans%M * modInverse(((n%M*(n-1)%M)%M * modInverse(2,M)%M)%M,M)%M)%M;

    cout << (1%M + ans%M)%M << "\n";


    return 0;}