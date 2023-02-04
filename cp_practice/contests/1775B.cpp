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

        vector<int> a[n];
        vector<pii> h;
        map<int,deq> cnt;
        rp(i,0,n){
            int x;
            cin >> x;
            rp(j,0,x){
                int y;
                cin >> y;
                a[i].pb(y);
                cnt[y].pb(i);
            }
        }

        for(auto i : cnt){
            h.pb({i.s.size(),i.f});
        }

        sort(h.begin(),h.end());

        mii used;
        for(auto i : h){
            bool check = false;
            for(auto j : cnt[i.s]){
                if(used[j]==1){
                    check = true;
                    break;
                }
            }
            if(!check){
                used[cnt[i.s][0]] = 1;
            }
        }

        bool ans = false;

        for(int i = 0; i < n; i++){
            if(used[i]==0){
                ans = true;
                break;
            }
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;}