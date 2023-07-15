#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,p;
    cin >> n >> p;

    deq every;
    set<int> arr;

    rp(i,0,n){
        int a;
        cin >> a;
        arr.insert(a);
    }

    for(auto i : arr)every.pb(i);

    for(auto i : every){
        int x = i;
        while(x > 0){
            if((x & 1) != 0){
                x >>= 1;
                if(arr.count(x)){
                    arr.erase(i);
                    break;
                }
            }
            else if(x >= 4 && (x&1) == 0 && (x&2) == 0){
                x >>= 2;
                if(arr.count(x)){
                    arr.erase(i);
                    break;
                }
            }
            else{
                break;
            }
        }
    }

    // for(auto i : arr)cout << i << " ";

    int dp[p+1];
    dp[p] = 0;
    
    rep(i,p-1,0){
        dp[i] = 1%M;
        if(i+1 <= p)dp[i] = (dp[i]%M + dp[i+1]%M)%M;
        if(i+2 <= p)dp[i] = (dp[i]%M + dp[i+2]%M)%M;
    }

    // rp(i,0,p+1)cout << dp[i] << " ";
    // cout << "\n";
    int ans = 0;
    for(auto i : arr){
        int x = i;
        int j = 0;
        while(((1LL)<<j) <= i){
            ++j;
        }
        --j;
        // cout << i << " " << j << "\n";
        if(j < p)ans = (ans%M + dp[j]%M)%M;
    }

    cout << ans << "\n";

    return 0;}