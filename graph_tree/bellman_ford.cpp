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

    int n,m;
    cin >> n >> m;
    vector<deq> edges; // edges[i] contains three integers a,b,c means a direct edge from a to b of weight c

    rp(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        deq test;
        test.pb(a);
        test.pb(b);
        test.pb(c);
        edges.pb(test);
    }
    int src;
    cin >> src;
    int distances[n];
    
    rp(i,0,n)distances[i] = INT_MAX;
    distances[src] = 0;

    rp(i,0,n-1){
        for(auto j : edges){
            int a = j[0], b = j[1], c = j[2];
            distances[b] = min(distances[b], distances[a] + c);
        }
    }

    for(auto i : edges){
        int a = j[0], b = j[1], c = j[2];
        if(distances[b] > distances[a] + c){
            cout << "Graph has a negative cycle\n";
            return 0;
        }
    }

    for(auto i : distances)cout << i << " ";

    return 0;}