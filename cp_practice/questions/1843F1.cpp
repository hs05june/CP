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

int dp[300007][4];
// 0 -> mini, 1 -> maxi, 2 -> mini ending , 3 -> maxi ending

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        dp[1][0] = 0; dp[1][1] = 1; 
        dp[1][2] = 0; dp[1][3] = 1;
        int z = 1;
        while(n--){
            char a;
            cin >> a;
            if(a == '+'){
                int x,y;
                cin >> x >> y;
                ++z;
                dp[z][2] = min(dp[x][2]+y,y);
                dp[z][3] = max(dp[x][3]+y,y);
                dp[z][0] = min(dp[x][0],dp[z][2]);
                dp[z][1] = max(dp[x][1],dp[z][3]);
                // cout << z << " " << dp[z][0] << " " << dp[z][1] << " " << dp[z][2] << " " << dp[z][3] << "\n";
            }
            else if(a == '?'){
                int x,y,z;
                cin >> x >> y >> z;
                if(z >= dp[y][0] && z <= dp[y][1]){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }

    }

    return 0;}