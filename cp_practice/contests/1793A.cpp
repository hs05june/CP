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

        int a,b;
        int n,m;

        cin >> a >> b;
        cin >> n >> m;

        if(n<=m){
            cout << min(a*n,b*n) << "\n";
            continue;
        }

        if(a<=b){
            int x = n/(m+1);
            cout << a*x*m + a*(n-x*(m+1)) << "\n";
            continue;
        }

        int x = n/(m+1);

        cout << min(b*n,a*x*m+b*(n-x*(m+1))) << "\n";
                
    }

    return 0;}