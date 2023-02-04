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
#define lb(a,b,c) lower_bound(a,b,c)
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
const ll M = 1000000007;
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n+1] = {0},ans[n+1] = {0};

        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }

        for(int i = 1; i <= n; i++){
            ans[i] = min(1+ans[i-1],arr[i]);
        }

        int cnt = 0;

        for(int i = 1; i <= n; i++){
            cnt+=ans[i];
        }

        cout << cnt << "\n";

    }

    return 0;}