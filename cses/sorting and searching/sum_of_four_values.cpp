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

    int n,x;
    cin >> n >> x;

    int arr[n];
    rp(i,0,n)cin >> arr[i];

    map<int,set<pii>> possible;

    rp(i,0,n){
        rp(j,i+1,n){
            possible[arr[i]+arr[j]].insert({i,j});
        }
    }

    rp(i,0,n){
        rp(j,i+1,n){
            int y = arr[i] + arr[j];
            int z = x - y;
            if(possible.count(z)){
                auto itr = possible[z].lower_bound(make_pair(j+1,0));
                if(itr!=possible[z].end()){
                    cout << (i+1) << " " << (j+1) << " " << ((*itr).f+1) << " " << ((*itr).s+1) << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;}