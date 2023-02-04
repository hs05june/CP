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

int arr[205][205];
int ans,sum;
int visited[205][205];
int n;

void solve(int a, int b, int value){
    if(a==n-1 && b==n-1){
        ans = max(ans,value);
        return;
    }
    int x = (a+1)%n,y = (b+1)%n;
    if(visited[x][b]==0){
        visited[x][b] = 1;
        solve(x,b,value+arr[x][b]);
        visited[x][b] = 0;
    }
    if(visited[a][y]==0){
        visited[a][y] = 1;
        solve(a,y,value+arr[a][y]);
        visited[a][y] = 0;
    }
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        cin >> n;

        rep(i,1,n){
            rep(j,1,n){
                cin >> arr[i][j];
                sum+=arr[i][j];
            }
        }

        rep(i,1,n){
            ans = max(ans,sum-arr[i][n+1-i]);
        }

        // visited[0][0] = 1;
        // solve(0,0,arr[0][0]);
        cout << ans << "\n";
    }

    return 0;}