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

        int n,w,h;
        cin >> n >> w >> h;

        int arr[n], brr[n];

        rp(i,0,n)cin >> arr[i];
        rp(i,0,n)cin >> brr[i];

        int mini = brr[0] + h - arr[0] - w;
        int maxi = brr[0] - h - arr[0] + w;
        bool ans = true;
        
        if(maxi < mini){
            ans = false;
            cout << "NO\n";
            continue;
        }

        rp(i,1,n){
            int mini1 = brr[i] + h - arr[i] - w;
            int maxi1 = brr[i] - h - arr[i] + w;
            maxi = min(maxi,maxi1);
            mini = max(mini,mini1);
            if(maxi < mini){
                ans = false;
                break;
            }
        }

        ans ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;}