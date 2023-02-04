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

        int n;
        cin >> n;

        int a[n];
        rp(i,0,n)cin >> a[i];

        int mex[n];
        set<int> h;
        rep(i,0,n){
            h.insert(i);
        }
        rp(i,0,n){
            h.erase(a[i]);
            mex[i] = *(h.begin());
        }

        int places[n+1] = {0};

        set<int> to_use;

        rp(i,1,n){
            if(mex[i]==mex[i-1]){
                places[mex[i]]++;
                to_use.insert(a[i]);
            }
        }

        int preffix[n+1] = {0};
        preffix[0] = places[0];

        rep(i,1,n){
            preffix[i] = preffix[i-1] + places[i];
        }
        int x = 0;
        ll ans = 1;
        for(auto i : to_use){
            ans = ((ans%M) * (((preffix[i]%M)- (x%M) + M)%M))%M;
            ++x;
        }
        // rep(i,0,n)cout << preffix[i] << " ";
        // cout << "\n";
        // for(auto i : to_use)cout << i << " ";
        // cout << "\n";
        // rp(i,0,n)cout << mex[i] << " ";
        // cout<<"\n";
        // rep(i,0,n)cout << places[i] << " ";
        // cout << "\n";
        cout << ans << "\n";
    }

    return 0;}