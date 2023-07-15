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

bool check(int mid, int n, int m, vector<deq>& values){
    set<int> shops;
    rp(i,0,n){
        rp(j,0,m){
            if(values[j][i] >= mid){
                if(shops.count(j))return true;
                shops.insert(j);
            }
        }
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int m,n;
        cin >> m >> n;

        vector<vector<ll>> values;

        int low = 1, high = LLONG_MAX;

        rp(i,0,m){
            deq temp;
            rp(j,0,n){
                int a;
                cin >> a;
                temp.pb(a);
            }
            values.pb(temp);
        } 

        rp(i,0,n){
            int x = 1;
            rp(j,0,m){
                x = max(x,values[j][i]);
            }
            high = min(high,x);
        }

        while(high - low > 1){
            int mid = (low+high)/2;
            if(check(mid,n,m,values)){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }

        if(check(high,n,m,values))cout << high << "\n";
        else cout << low << "\n";

    }

    return 0;}