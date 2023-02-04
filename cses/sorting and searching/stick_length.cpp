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

    int n;
    cin >> n;

    mii a;
    int arr[n];
    int sum = 0;
    rp(i,0,n){
        int x;
        cin >> x;
        sum += x;
        a[x]++;
        arr[i] = x;
    }

    int ans = LLONG_MAX;

    int centers[4];
    centers[0] = sum/n;
    centers[1] = (sum/n)+1;

    sort(arr,arr+n);
    centers[2] = arr[n/2];
    if(n>1)centers[3] = arr[n/2-1];

    rp(i,0,4){
        if(n==1 && i==3)continue;
        int z = 0;
        rp(j,0,n){
            z+=abs(arr[j]-centers[i]);
        }
        ans = min(ans,z);
    }

    cout << ans << "\n";

    return 0;}