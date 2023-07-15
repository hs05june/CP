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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        string a;
        cin >> a;

        int n = sz(a);

        int preff[n+1][2];
        rp(i,0,n+1){
            preff[i][0] = preff[i][1] = 0;
        }

        rp(i,0,n){
            preff[i+1][0] = preff[i][0];
            preff[i+1][1] = preff[i][1];
            preff[i+1][a[i]-'0']++;
        }

        int ans = INT_MAX;

        rp(i,0,n+1){
            int x = preff[i][1];
            int low = i, high = n;
            while(high - low > 1){
                int mid = (low + high) / 2;
                int ones = x + preff[n][1] - preff[mid][1];
                int zeros = preff[mid][0] - preff[i][0];
                ans = min(ans,max(zeros,ones));
                if(zeros >= ones){
                    high = mid;
                }
                else{
                    low = mid + 1;
                }
            }
            int ones = x + preff[n][1] - preff[low][1];
            int zeros = preff[low][0] - preff[i][0];
            ans = min(ans,max(zeros,ones));
            ones = x + preff[n][1] - preff[high][1];
            zeros = preff[high][0] - preff[i][0];
            ans = min(ans,max(zeros,ones));
        }

        cout << ans << "\n";

    }

    return 0;}