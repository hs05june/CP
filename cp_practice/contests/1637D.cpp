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

int maxi;
int dp[107][10007];
deq diff;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        maxi = 0;
        int a[n],b[n];
        rp(i,0,n)cin >> a[i];
        rp(i,0,n)cin >> b[i];

        diff.clear();

        rp(i,0,n){
            diff.pb(abs(a[i]-b[i]));
        }

        for(auto i : diff){
            maxi+=i;
        }
        string x = "";
        rp(i,0,n)x.pb('0');
        rp(i,0,n+1){
            rp(j,0,maxi+1){
                dp[i][j] = 0;
            }
        }

        rp(i,0,n+1){
            dp[i][0] = 1;
        }

        rp(i,1,n+1){
            rp(j,1,maxi+1){
                dp[i][j] |= dp[i-1][j];
                if(j-diff[i-1]>=0)dp[i][j] |= dp[i-1][j-diff[i-1]];
            }
        }
        int x1,x2;
        x1 = maxi/2;
        x2 = (maxi%2==0) ? maxi/2 : maxi/2+1;
        while(x2<=maxi && dp[n][x2]!=1){
            x2++;
        }
        while(x1>0 && dp[n][x1]!=1){
            x1--;
        }
        for(int i = n-1; i>=0; i--){
            if(dp[i][x2-diff[i]]==1){
                x[i] = '1';
                x2-=diff[i];
            }
        }

        rp(i,0,n){
            int mini = min(a[i],b[i]);
            int maxi = max(a[i],b[i]);
            if(x[i]=='1'){
                a[i] = maxi;
                b[i] =  mini;
            }
            else{
                a[i] = mini;
                b[i] = maxi;
            }
        }

        int ans = 0;
        rp(i,0,n){
            rp(j,i+1,n){
                ans+=((a[i]+a[j])*(a[i]+a[j]));
            }
        }
        rp(i,0,n){
            rp(j,i+1,n){
                ans+=((b[i]+b[j])*(b[i]+b[j]));
            }
        }
        cout << ans << "\n";
    }

    return 0;}