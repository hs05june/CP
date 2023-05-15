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

        int n,q;
        cin >> n >> q;

        int arr[n+1] = {0}, sum = 0;
        int preffix[n+1] = {0};
        preffix[0] = 0;
        arr[0] = 0;
        rp(i,1,n+1){
            cin >> arr[i];
            sum += arr[i]; 
            preffix[i] = preffix[i-1]+arr[i];
        }

        while(q--){
            int l,r,k;
            cin >> l >> r >> k;

            int sum1 = sum + k*(r-l+1) - (preffix[r]-preffix[l-1]);
            if(sum1&1){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }

    }

    return 0;}