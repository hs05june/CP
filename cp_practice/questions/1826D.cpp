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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n+1];
        arr[0] = 0;
        rp(i,1,n+1)cin >> arr[i];

        int peeche[n+2],aage[n+2];
        peeche[0] = peeche[n+1] = aage[0] = aage[n+1] = LLONG_MIN;

        rp(i,1,n+1){
            peeche[i] = max(peeche[i-1],arr[i]+i);
        }
        rep(i,n,1){
            aage[i] = max(aage[i+1],arr[i]-i);
        }
        int ans = 0;
        rp(i,2,n){
            ans = max(ans,arr[i]+peeche[i-1]+aage[i+1]);
        }
        cout << ans << "\n";
    }

    return 0;}