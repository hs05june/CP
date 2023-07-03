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

    int n,m;
    cin >> n >> m;

    deq graph[n+1];
    int indegree[n+1];

    rp(i,0,n+1)indegree[i] = 0;

    rp(i,0,m){
        int a,b;
        cin >> a >> b;
        indegree[b]++;
        graph[a].pb(b);
    }

    multiset<pii> kahn;
    deq st;

    rp(i,1,n+1){
        kahn.insert({indegree[i],i});
    }

    while(!kahn.empty() && (*(kahn.begin())).f == 0){
        auto itr = *(kahn.begin());
        int x = itr.f, y = itr.s;
        kahn.erase(kahn.begin());
        st.pb(y);
        for(auto i : graph[y]){
            kahn.erase({indegree[i],i});
            indegree[i]--;
            kahn.insert({indegree[i],i});
        }
    }

    if(st.size()!=n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(auto i : st)cout << i << " ";

    return 0;}