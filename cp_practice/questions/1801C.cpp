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
 
        deq arr[n];
        map<int,deq> store;
        set<int>uniq;
 
        rp(i,0,n){
            int siz;
            cin >> siz;
            rp(j,0,siz){
                int x;
                cin >> x;
                if(arr[i].empty() || x > arr[i].back()){
                    arr[i].pb(x);
                    store[x].pb(i);
                    uniq.insert(x);
                }
            }
        }
 
       mii dp;
 
        deq ele;
        for(auto i : uniq)ele.pb(i);
 
        reverse(all(ele));
        int ans = 0;
 
        rp(i,0,sz(ele)){
            if(i==0){
                dp[ele[i]] = 1;
                ans = 1;
                continue;
            }
            for(auto j : store[ele[i]]){
                auto itr = lower_bound(all(arr[j]),ele[i]);
                int avail = arr[j].end() - itr;
                int last = arr[j].back();
                if(ele[i]==last) dp[ele[i]] = max(dp[ele[i]],1+ans);
                else dp[ele[i]] = max(dp[ele[i]],avail+dp[last]-1);
            }
            ans = max(dp[ele[i]],ans);
        }   
 
        cout << ans << "\n";  
 
    }
 
    return 0;}