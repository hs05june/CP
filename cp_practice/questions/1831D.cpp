#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
// #define int long long
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

int cnt[640][200007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n+1], b[n+1];
        a[0] = 0, b[0] = 0;

        // rp(i,0,n+1){
        //     for(int j = 0; j < 640 ;j++){
        //         cnt[j][i] = 0;
        //     }
        // }

        rp(i,1,n+1)cin >> a[i];
        rp(i,1,n+1)cin >> b[i];
        
        rp(i,1,n+1){
            if(a[i]<=sqrtl(2*n))cnt[a[i]][b[i]]++;
        }

        ll ans = 0;

        rp(i,1,n+1){
            int x = a[i];
            for(int j = 1; j <= min(((2*n)/x)+1,a[i]-1); j++){
                int y = a[i] * j - b[i];
                if(y>=1 && y<=n)ans += (cnt[j][a[i] * j - b[i]] + 0LL);
            }
        }

        rp(i,1,sqrtl(2*n)+1){
            int x = i*i;
            if(x>2*n)break;
            for(int j = 1; j <= n ; j++){
                int y = x - j;
                if(y < j)break;
                if(y==j){
                    if(y>=1 && y<=n)ans += (cnt[i][j] * 1LL * (cnt[i][j] - 1)) / 2;
                }
                else{
                    if(y>=1 && y<=n)ans += (cnt[i][j] * 1LL * cnt[i][y]);
                }
            }
        }

        cout << ans << "\n";

        rp(i,1,n+1){
            if(a[i]<=sqrtl(2*n))cnt[a[i]][b[i]]--;
        }

    }

    return 0;}