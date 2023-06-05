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

// 0 -> lefti, 1 -> righti
int n;
int dp[200007][2];
int c[200007];
pii arr[200007];
set<pii> lefti, righti;
map<int,mii> cnt;

int solve(int i, int dir){
    if(dp[i][dir]!=-1)return dp[i][dir];
    if(dir == 0){
        if(sz(cnt[arr[i].s])>=2){
            for(auto j : cnt[arr[i].s]){
                if(j.f != c[i])return dp[i][dir] = j.s;
            }
        }
        auto itr = righti.upper_bound({-arr[i].s,n+1});
        if(itr == righti.end()){
            return dp[i][0] = 0;
        }
        if(c[(*itr).s]!=c[i]){
            return dp[i][0] = (*itr).s;
        }
        return dp[i][0] = solve((*itr).s,0);
    }
    if(dir == 1){
        if(sz(cnt[arr[i].f])>=2){
            for(auto j : cnt[arr[i].f]){
                if(j.f != c[i])return dp[i][dir] = j.s;
            }
        }
        auto itr = lefti.upper_bound({arr[i].f,n+1});
        if(itr == lefti.end()){
            return dp[i][1] = 0;
        }
        if(c[(*itr).s] != c[i]){
            return dp[i][1] = (*itr).s;
        }
        return dp[i][1] = solve((*itr).s,1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        cin >> n;
        lefti.clear();
        righti.clear();
        cnt.clear();

        map<int, map<int,deq>> m;

        dp[0][0] = dp[0][1] = -1;
        rp(i,1,n+1){
            cin >> arr[i].f >> arr[i].s >> c[i];
            m[arr[i].f][0].pb(i);
            m[arr[i].s][1].pb(i);
            if(cnt[arr[i].s][c[i]]==0)cnt[arr[i].s][c[i]] = i;
            if(cnt[arr[i].f][c[i]]==0)cnt[arr[i].f][c[i]] = i;
            righti.insert({-arr[i].s,i});
            lefti.insert({arr[i].f,i});
            dp[i][0] = dp[i][1] = -1;
        }

        int ans[n+1];
        rp(i,0,n+1)ans[i] = LLONG_MAX;
        mii color;
        set<int> multi, ele;
        for(auto i : m){
            for(auto j : m[i.f][0]){
                color[c[j]]++;
                multi.insert(c[j]);
                ele.insert(j);
            }
            if(sz(multi)>=2){
                for(auto j : ele){
                    ans[j] = 0;
                }
                ele.clear();
            }
            for(auto j : m[i.f][1]){
                color[c[j]]--;
                ele.erase(j);
                if(color[c[j]]==0)multi.erase(c[j]);
            }
        }
        rp(i,1,n+1){
            int z = solve(i,0);
            z = solve(i,1);
        }
        rp(i,1,n+1){
            // cout << dp[i][0] << " " << dp[i][1] << "\n";
            int x1 = dp[i][0];
            if(x1!=0)ans[i] = min(ans[i], (arr[i].f <= arr[x1].s) ? 0 : abs(arr[i].f-arr[x1].s));
            int x2 = dp[i][1];
            if(x2!=0)ans[i] = min(ans[i],arr[i].s >= arr[x2].f ? 0 : abs(arr[i].s-arr[x2].f));
        }

        rp(i,1,n+1)cout << ans[i] << " ";

        cout << "\n";

    }

    return 0;}