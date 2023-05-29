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
const ll M = 998244353;
using namespace std;

int sum[1000007];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    int x = 1;
    deq positions;
    while(x <= ((1LL)<<(19))){
        positions.pb(x);
        x*=2;
    }

    while(t--){

        int n;
        cin >> n;

        int arr[n+1];
        arr[0] = 0;
        rp(i,1,((1LL)<<n)+1)cin >> arr[i];

        rp(i,1,((1LL)<<n)+1){
            if(arr[i]!=-1){
                auto itr = lower_bound(all(positions),i);
                int x = itr - positions.begin();
                sum[x]+=((1LL)<<(n-x));
                // cout << arr[i] << " " << x << " " << sum[x] << "\n";
            }
            // cout << i << "\n";
        }

        // rp(i,0,n+1)cout << sum[i] << " ";
        // cout << "\n";
        rep(i,n,0){
            sum[i]+=sum[i+1];
        }
        rp(i,0,n+1)cout << sum[i] << " ";
        cout << "\n";
        int k = n-1;
        int ans = ((1LL)<<n) - sum[0];
        cout << ans << "\n";
        rp(i,1,n+1){
            int left = ((1LL)<<k) - sum[i];
            int y = 0;
            rp(j,((1LL) << (i-1))+1,((1LL) << i)+1){
                if(arr[j]!=-1)continue;
                y = (y%M + left%M)%M;
            }
            // cout << left << " " << ans  << " " << y << "\n";
            ans = (ans%M * y%M)%M;
            --k;
        }
        cout << ans%M << "\n";
    }

    return 0;}