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

        int n,c;
        cin >> n >> c;

        deque<pair<int,pii>> costs;

        int done[n+1];

        int arr[n+1];

        rep(i,0,n){
            done[i] = 0;
        }

        rep(i,1,n){
            cin >> arr[i];
        }

        rep(i,1,n){
            int x = i + arr[i];
            int y = n + 1 - i + arr[i];
            costs.pb({x,{i,0}});
            costs.pb({y,{i,n+1}});
        }

        sort(all(costs));

        for(auto i : costs){
            cout << i.f << " " << i.s.f << " " << i.s.s << "\n";
        }

        int z = 0;
        vector<pair<int,pii>> poi;
        pair<int,pii> daalna;

        for(int i = 0 ; i < costs.size() ; i++){
            int y = costs[i].s.s;
            if(y==0){
                daalna = costs[i];
                z = i+1;
                break;
            }
            poi.pb(costs[i]);
        }

        vector<pii> next;
        next.pb({daalna.f,daalna.s.f});

        for(auto i : poi){
            next.pb({i.f,i.s.f});
        }

        for(int i = z; i < costs.size(); i++){
            next.pb({costs[i].f,costs[i].s.f});
        }

        for(auto i : next){
            cout << i.f << " " << i.s << "\n";
        }
        int ans = 0;

        for(auto i : next){
            if(done[i.s]==0){
                if(c>=i.f){
                    ans++;
                    done[i.s] = 1;
                    c-=i.f;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;}