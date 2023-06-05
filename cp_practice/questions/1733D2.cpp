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

long double n, x, y;
deq diff;
string a, b;
long double dp[5007];

long double solve(int index, int left){
    if(index >= sz(diff))return 0;
    if(dp[index]!=-1)return dp[index];
    long double ans = y / 2 + solve(index+1, left-1);
    if(index + 1 < sz(diff))ans = min(ans, x*(diff[index+1] - diff[index]) + solve(index+2, left-2));
    return dp[index] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        diff.clear();
        cin >> n >> x >> y;
        cin >> a >> b;

        rp(i,0,n+1){
            dp[i] = -1;
        }

        rp(i,0,n){
            if(a[i]!=b[i])diff.pb(i);
        }

        if(sz(diff)%2 == 1){
            cout << "-1\n";
            continue;
        }

        if(sz(diff)==0){
            cout << "0\n";
            continue;
        }

        if(x >= y){
            if(sz(diff)>2 || abs(diff[1] - diff[0]) != 1){
                cout << (int)(sz(diff)/2 * y) << "\n";
            }
            else {
                x > 2*y ? cout << (int)(2*y) << "\n" : cout << (int)(x) << "\n";
            }
            continue;
        }

        cout << (int)solve(0,sz(diff)) << "\n";

    }

    return 0;}