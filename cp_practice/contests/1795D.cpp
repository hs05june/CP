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
const ll M = 998244353;
using namespace std;

int factorial[300007];

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
    factorial[0] = factorial[1] = 1;

    rp(i,2,300003){
        factorial[i] = (i%M * factorial[i-1]%M)%M;
    }
    // cin >> t;

    while(t--){

        int n;
        cin >> n;

        int edge[n/3][3];

        rp(i,0,n/3){
            cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
            sort(edge[i],edge[i]+3);
        }

        int ans = 1;

        rp(i,0,n/3){
            if(edge[i][0] == edge[i][2]){
                ans = (ans%M * 3%M)%M;
            }
            else if(edge[i][0]==edge[i][1]){
                ans = (ans%M * 2%M)%M;
            }
        }

        int x = factorial[n/3]%M, y = ((factorial[n/6]%M) * (factorial[n/6]%M))%M;
        ans = (((ans%M * x%M)%M) * modInverse(y,M)%M)%M;
        cout << (ans%M) << "\n";

    }

    return 0;}