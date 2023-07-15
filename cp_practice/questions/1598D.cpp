#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

        ll n;
        cin >> n;

        mii topic, difficulty;

        pii a[n];

        rp(i,0,n){
            cin >> a[i].f >> a[i].s;
            topic[a[i].f]++;
            difficulty[a[i].s]++;
        }

        ll exclude = 0;
        rp(i,0,n){
            exclude += ((topic[a[i].f]-1) * (difficulty[a[i].s]-1));
        }

        cout << (n*(n-1)*(n-2)) / 6 - exclude << "\n";

    }

    return 0;}