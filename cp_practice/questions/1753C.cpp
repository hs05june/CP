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
        int zero = 0, start = 0;

        int ans = 0;
        int numerator = ((n%M * (n-1)%M) * modInverse(2,M)%M)%M;

        int arr[n];
        rp(i,0,n){
            cin >> arr[i];
            zero += (arr[i]==0);
        }

        rp(i,0,zero){
            start += (arr[i]==0);
        }

        rp(i,start,zero){
            int x = ((zero - i)%M * (zero - i)%M)%M;
            int y = (numerator%M * modInverse(x,M)%M)%M;
            ans = (ans%M + y%M)%M;
        }

        cout << ans%M << "\n";

    }

    return 0;}