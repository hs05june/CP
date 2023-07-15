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
const ll M = 1000000007;
using namespace std;

int fenwick[90007];

void update(int x, int m){
    for(int i = x; i <= m; i += (i&(-i))){
        fenwick[i] ++;
    }
}

int solve(int x){
    int ans = 0;
    for(int i = x; i > 0; i -= (i & (-i))){
        ans += fenwick[i];
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
        
        int n,m;
        cin >> n >> m;
        map<int,deq> cnt;

        rp(i,0,n*m){
            int a;
            cin >> a;
            cnt[a].pb(i+1);
        }

        int fill[n][m];
        int row = -1, col = -1;
        int total = -1;
        for(auto i : cnt){
            total += sz(i.s);
            int r = total / m, c = total % m;
            int r1 = r, c1 = 0;
            rep(j,sz(i.s)-1,0){
                if(r1 == row && c1==0)c1 = col+1;
                fill[r1][c1] = i.s[j];
                c1++;
                if(r1 == r && c1 > c)c1 = 0, r1--;
                if(c1 == m)c1 = 0, r1--;
            }
            row = r, col = c;
        }

        // rp(i,0,n){
        //     rp(j,0,m){
        //         cout << fill[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        ll ans = 0;

        rp(i,0,n){
            rp(j,0,n*m+1)fenwick[j] = 0;
            rp(j,0,m){
                ans += solve(fill[i][j]);
                update(fill[i][j],n*m);
            }
            // cout << ans << "\n";
        }

        cout << ans << "\n";

    }

    return 0;}