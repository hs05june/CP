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

    int t = 1;
    cin >> t;

    while(t--){

        int x,y;
        cin >> x >> y;

        if(abs(x-y)==1){
            cout << "2\n" << x << " " << y << "\n";
            continue;
        }

        deq ans;
        int start = x-1;

        ans.pb(start);
        ans.pb(x);
        int z = start;

        while(z>=y){
            ans.pb(z);
            --z;
        }

        z = y+1;

        while(z<start){
            ans.pb(z);
            ++z;
        }

        cout << ans.size() << "\n";

        for(auto i : ans){
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;}