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

int n;
int arr[100007];
int dp[100007];
vector<pii> segments;

int solve(int index){
    if(index>=sz(segments))return 0;
    if(dp[index]!=-1)return dp[index];
    pii x = {segments[index].s+1,0};
    auto itr = upper_bound(all(segments),x);
    return dp[index] = max(solve(index+1),1+solve(itr-segments.begin()));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        cin >> n;
        segments.clear();
        rp(i,1,n+1)cin >> arr[i];

        rp(i,0,n+1)dp[i] = -1;

        map<int,deq> store;
        
        int x = 0;
        store[0].pb(0);
        rp(i,1,n+1){
            x^=arr[i];
            store[x].pb(i);
        }
        
        for(auto i : store){
            rp(j,1,sz(store[i.f])){
                segments.pb({store[i.f][j-1]+1,store[i.f][j]});
            }
        }
        sort(all(segments));
        int ans = solve(0);
        cout << n - ans << "\n";
    }

    return 0;}