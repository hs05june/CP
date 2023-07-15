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

bool solve(ll a, ll b, ll x){
    if(a==x || b==x)return true;
    if(a==0 || b==0)return false;
    ll y1 = a%b, y2 = a / b;
    if(x >= y1 && x <= a){
        // int k = (a+b-x)/b;
        if((a+b-x)%b == 0)return true;
    }
    return solve(b,y1,x);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        ll a,b,x;
        cin >> a >> b >> x;

        if(a < b)swap(a,b);

        if(solve(a,b,x)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;}