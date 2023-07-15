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

    int n, m;
    cin >> n >> m;

    char arr[n][m];

    rp(i,0,n){
        rp(j,0,m){
            cin >> arr[i][j];
        }
    }

    int values[m];
    rp(i,0,m) values[i] = 0;
    rp(i,1,m){
        rp(j,0,n){
            if(j-1 >= 0 && i-1 >=0 && arr[j-1][i] == 'X' && arr[j][i-1] == 'X') values[i]++;
        }
    }

    rp(i,1,m) values[i] += values[i-1];

    int q;
    cin >> q;

    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        (values[b] - values[a]) == 0 ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;}