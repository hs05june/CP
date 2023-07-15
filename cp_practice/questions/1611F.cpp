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

        int n, k;
        cin >> n >> k;

        ll arr[n+1], pref[n+1];
        arr[0] = 0, pref[0] = 0;

        rp(i,1,n+1) cin >> arr[i];
        rp(i,1,n+1) pref[i] = pref[i-1] + arr[i];

        map<ll, deque<int>> cnt;
        mii ans;
        set<pii> present;

        rp(i,1,n+1){
            present.insert({(k-pref[i-1]),i});
            ll z = -pref[i];
            while(!present.empty() && (*present.begin()).f < z){
                ans[(*present.begin()).s] = i;
                present.erase(present.begin());
            }
        }

        while(!present.empty()){
            ans[(*present.begin()).s] = n+1;
            present.erase(present.begin());
        }

        pii seg; ll diff = 0;
        for(auto i : ans){
            if(i.s - i.f > diff){
                seg = {i.f,i.s-1};
                diff = i.s - i.f;
            }
        }

        diff == 0 ? cout << "-1\n" : cout << seg.f << " " << seg.s << "\n"; 

    }

    return 0;}