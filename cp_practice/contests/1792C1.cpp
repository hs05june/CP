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

        mii index;
        rp(i,1,n+1){
            cin >> arr[i];
            index[arr[i]] = i;
        }

        int mini = 0,maxi = n+1,prev = index[1];

        vector<pii> sotred;

        int sta = n/2;
        int en = (n%2)==0 ? n/2+1 : n/2+2;

        for(int i = 1; i <= n; i++){
            int x = i,in = index[i];
            int prev = index[i];
            while(i<=n && index[i]>=prev){
                prev = index[i];
                ++i;
            }
            --i;

            sotred.pb({x,i});
        }

        int ans = n/2;

        for(auto i : sotred){
            if(i.f<=sta && i.s>=en){
                ans = max(i.f-1,n-i.s);
            }
        }

        cout << ans << "\n";

    }

    return 0;}