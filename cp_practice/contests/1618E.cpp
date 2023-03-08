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

        int n;
        cin >> n;

        int x = (n*(n+1))/2;

        int arr[n+1];
        arr[0] = 0;

        int sum = 0;

        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        if(sum%x!=0){
            cout << "NO\n";
            continue;
        }

        int y = sum / x;

        int ans[n+1];
        ans[1] = y;
        bool check = true;
        for(int i = 2; i <= n; i++){
            if(!check)continue;
            int sum1 = arr[i] - arr[i-1];
            int z = y - sum1;
            if(z<=0 || z%n!=0){
                check = false;
                continue;
            }
            ans[i] = z/n;
            ans[1]-= ans[i];
        }

        if(!check || ans[1]<=0){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        rp(i,1,n+1){
            cout  << ans[i] << " ";
        }

        cout << "\n";

    }

    return 0;}