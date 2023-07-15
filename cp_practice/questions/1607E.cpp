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

pii path(char x){
    if(x=='U')return make_pair(-1,0);
    if(x=='D')return make_pair(1,0);
    if(x=='L')return make_pair(0,-1);
    if(x=='R')return make_pair(0,1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        ll n,m;
        cin >> n >> m;

        string a;
        cin >> a;
        ll len = sz(a);

        ll maxiRow = 0, miniRow = 0, maxiCol = 0, miniCol = 0;
        ll row = 0, col = 0;
        int last = -1;

        rp(i,0,len){
            row += path(a[i]).f;
            col += path(a[i]).s;
            ll maxirow = max(maxiRow, row);
            ll maxicol = max(maxiCol, col);
            ll minirow = min(miniRow, row);
            ll minicol = min(miniCol, col);
            // cout << i << " " << minirow << " " << maxirow << " " << minicol << " " << maxicol << "\n";
            if(abs(maxirow - minirow) >= n){break;}
            if(abs(maxicol - minicol) >= m){break;}
            maxiRow = maxirow, miniCol = minicol, maxiCol = maxicol, miniRow = minirow; 
        }
        // cout << 
        cout << abs(miniRow)+1 << " " << abs(miniCol)+1 << "\n";

    }

    return 0;}