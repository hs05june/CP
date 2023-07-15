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

        ll n,k;
        cin >> n >> k;
        ll sum = 0;
        
        deq arr;
        rp(i,0,n){
            int a;
            cin >> a;
            sum += a;
            arr.pb(a);
        }

        if(sum <= k){
            cout << "0\n";
            continue;
        }

        sort(all(arr));

        ll ans = LLONG_MAX;
        ll mini = arr[0], y = arr[0];
        ll x = 0;
        ans = min(ans,sum - k);
        ll z = 1;
        
        for(int i = n-1; i >= 1; i--){
            y += arr[i];
            z++;
            if(arr[i]!=mini)x++;
            ll kt = z*mini;
            if((sum - y + kt) <= k){
                ans = min(ans,x);
            }
            else{
                ll diff = ceil((long double)(sum - y + kt - k) / (long double)z);
                ans = min(ans,diff+z-1);
            }
        }

        cout << ans << "\n";
    }

    return 0;}