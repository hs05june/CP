#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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

int pref[5007][5007],suff[5007][5007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n+5] = {0};

        rep(i,1,n){
            cin >> arr[i];
        }

        for(int i = 0; i <= n+2; i++){
            for(int j = 0; j <= n+2; j++){
                pref[i][j] = 0;
                suff[i][j] = 0;
            }
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j <i; j++){
                pref[i][j] = pref[i][j-1] + (arr[j]<arr[i]);
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = n; j > i; j--){
                suff[i][j] = suff[i][j+1] + (arr[i]>arr[j]);
            }
        }

        ll ans = 0;

        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                ans+=(pref[j][i-1] * 1LL *suff[i][j+1]);
            }
        }

        cout << ans << "\n";
    }

    return 0;}