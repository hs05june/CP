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
    // cin >> t;

    while(t--){

        int n;
        cin >> n;

        string a;
        cin >> a;

        int cnt[2] = {0,0};

        rp(i,0,n){
            cnt[(a[i] == '+')]++;
        }

        int y=abs(cnt[0]-cnt[1]);

        int m;
        cin >> m;

        while(m--){
            int a,b;
            cin >> a >> b;
            if(a<b){
                swap(a,b);
            }
            if(a==b){
                cnt[0]==cnt[1] ? cout << "YES\n" : cout << "NO\n";
                continue;
            }
            int x = ((b*y)/(a-b));
            ((((b*y)%(a-b))==0) && x<=min(cnt[0],cnt[1])) ? cout << "YES\n" : cout << "NO\n";
        }

    }

    return 0;}