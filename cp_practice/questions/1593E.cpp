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

        int n,k;
        cin >> n >> k;

        set<int> graph[n+1];
        int ans[n+1];
        int cnt[n+1], remove[n+1];
        rp(i,0,n+1)ans[i] = 0, cnt[i] = 0, remove[i] = 0;
        rp(i,1,n){
            int a,b;
            cin >> a >> b;
            graph[a].insert(b);
            graph[b].insert(a);
        }

        set<pii> every;
        rp(i,1,n+1)cnt[i] = sz(graph[i]);
        rp(i,1,n+1) every.insert({sz(graph[i]),i});
        int x = 1;
        while(!every.empty()){
            set<int> change;
            while(!every.empty() && (*every.begin()).f <= 1){
                int z = (*every.begin()).s;
                ans[z] = x;
                for(auto i : graph[z]){
                    graph[i].erase(z);
                    change.insert(i);
                }
                graph[z].clear();
                change.insert(z);
                remove[z] = 1;
                every.erase(every.begin());
            }
            for(auto i : change){
                every.erase({cnt[i],i});
                cnt[i] = sz(graph[i]);
                if(remove[i]!=1)every.insert({cnt[i],i});
            }
            ++x;
        }

        ll check = 0;
        // rp(i,1,n+1) cout << ans[i] << " ";
        rp(i,1,n+1)check += (ans[i]>k);

        cout << check << "\n";
    }

    return 0;}