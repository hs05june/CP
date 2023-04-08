/*
    Find longest increasing sequence, and print it.
*/
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

        int arr[n+1];
        arr[0]= 0;
        int dp[100];
        
        rp(i,0,100)dp[i] = 0;

        rp(i,1,n+1)cin >> arr[i];

        rp(i,1,n+1){
            rep(j,i-1,0){
                if(j==0){
                    dp[i] = max(dp[i],1LL);
                }
                else if(arr[j] < arr[i]){
                    dp[i] = max(dp[i], 1LL + dp[j]);
                }
            }
        }

        rp(i,0,n+1)cout << dp[i] << " ";
        cout << "\n";
        deq ans;
        int ans1 = 0, index = 0;
        
        rp(i,0,n+1){
            if(ans1 < dp[i]){
                ans1 = dp[i];
                index = i;
            }
        }

        rep(i,index,1){
            if(dp[i]==ans1){
                if(ans.empty() || ans.back()>arr[i]){
                    ans.pb(arr[i]);
                    ans1--;
                }
            }
        }

        reverse(all(ans));
        for(auto i : ans)cout << i << " ";

    }

    return 0;}