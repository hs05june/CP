#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = LLONG_MAX;
using namespace std;

ll dp[20][11][2];

ll solve(int tight, int ind, int dig, int n, string& a){
    if(ind >= n)return 1;
    if(dp[ind][dig][tight] != -1)return dp[ind][dig][tight];
    if(dig == 10){
        ll ans = solve(0, ind+1, 10, n, a)%M;
        rp(i,1,10){
            ans = (ans%M + solve(0, ind+1,i,n,a)%M)%M;
        }
        return dp[ind][dig][tight] = ans;
    }
    else if(tight == 0){
        ll ans = 0;
        rp(i,0,10){
            if(dig != i)ans = (ans%M + solve(0,ind+1,i,n,a)%M)%M;
        }
        return dp[ind][dig][tight] = ans;
    }
    else if(tight == 1){
        int z = a[ind] - '0';
        ll ans = 0;
        rp(i,0,z){
            if(dig != i)ans = (ans%M + solve(0,ind+1,i,n,a)%M)%M;
        }
        if(dig != z)ans = (ans%M + solve(1,ind+1,z,n,a)%M)%M;
        return dp[ind][dig][tight] = ans;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    string a,b;
    cin >> a >> b;

    rp(i,0,20){
        rp(j,0,11)dp[i][j][0] = dp[i][j][1] = -1;
    }

    ll ans1 = 0;
    int initial = b[0] - '0';
    rp(i,1,initial){
        ans1 = (ans1%M + solve(0,1,i,b.size(),b)%M)%M;
    }

    if(b != "0")ans1 = (ans1%M + solve(0,1,10,b.size(),b)%M)%M;
    ans1 = (ans1%M + solve(1,1,initial,b.size(),b)%M)%M;

    rp(i,0,20){
        rp(j,0,11)dp[i][j][0] = dp[i][j][1] = -1;
    }
    
    ll ans2 = 0;
    initial = a[0] - '0';
    rp(i,1,initial){
        ans2 = (ans2%M + solve(0,1,i,a.size(),a)%M)%M;
    }
    if(a != "0")ans2 = (ans2%M + solve(0,1,10,a.size(),a)%M)%M;
    ans2 = (ans2%M + solve(1,1,initial,a.size(),a)%M)%M;

    ll ans = ans1 - ans2;
    bool check = true;
    

    rp(i,0,a.size()-1){
        if(a[i]==a[i+1])check = false;
    }

    if(check)ans++;

    // cout << ans1 << " " << ans2 << "\n";
    cout << ans << "\n";

    return 0;}