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

        int a[n],b[n];

        rp(i,0,n){cin >> a[i] >> b[i];}

        int ans = 1;

        int nec = b[0], hcf = a[0]*b[0];
        
        rp(i,1,n){
            hcf = __gcd(hcf,a[i]*b[i]);
            nec = (nec*b[i])/__gcd(nec,b[i]);
            if(hcf%nec!=0){
                ans++;
                hcf = a[i]*b[i];
                nec = b[i];
            }
        }

        cout << ans << "\n";

    }

    return 0;}