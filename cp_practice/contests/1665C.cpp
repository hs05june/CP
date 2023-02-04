#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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

        mii parent;

        rp(i,1,n){
            int x;
            cin >> x;
            parent[x]++;
        }

        deq cnt;

        cnt.pb(1);
        for(auto i : parent){
            cnt.pb(i.s);
        }

        sort(cnt.begin(),cnt.end());
        reverse(cnt.begin(),cnt.end());

        multiset<int> remain;
        int ans = cnt.size(),x = cnt.size();

        for(auto i : cnt){
            int y = i<=x ? 0 : (i-x);
            remain.insert(y);
            --x;
        }

        int y = 0; int h = *(--remain.end()) - y;

        while(h>0){
            int z = *(--remain.end());
            remain.erase((--remain.end()));
            remain.insert(z-1);
            ++y;
            h = *(--remain.end()) - y;
        }

        cout << ans + y << "\n";

    }

    return 0;}