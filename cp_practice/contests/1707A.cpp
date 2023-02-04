//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
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

    int t; cin >> t;

    while(t--){
        int n,q;
        cin >> n >> q;
        mii cnt;
        int a[n];

        rp(i,0,n)cin >> a[i];

        int ans[n] = {0};

        int endq = 0;

        for(int i = n - 1; i >= 0; i--){
            if(a[i]<=endq){
                ans[i] = 1;
            }
            else if(endq<q){
                ans[i] = 1;
                endq++;
            }
            else{
                ans[i] = 0;
            }
        }

        rp(i,0,n)cout << ans[i];
        cout << "\n";
    }

    return 0;}