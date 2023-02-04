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

int solve(int index, int green, int blue, int arr[], int h,int n){
    if(index==n)return 0;
    int ans = 0;
    if(h>arr[index]){
        ans = 1 + solve(index+1,green,blue,arr,(h+(arr[index]/2)),n);
    }
    else{
        if(green>0){
            ans = max(ans,solve(index,green-1,blue,arr,2*h,n));
        }
        if(blue>0){
            ans = max(ans,solve(index,green,blue-1,arr,3*h,n));
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,h;
        cin >> n >> h;

        int arr[n];

        rp(i,0,n){
            cin >> arr[i];
        }

        sort(arr,arr+n);
        int ans = solve(0,2,1,arr,h,n);
        cout << ans << "\n";
    }

    return 0;}