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

int n;
pii arr[200007];

bool check(int mid){
    int ans = 0, z = mid;
    rp(i,0,n){
        if(arr[i].f >= (z-1) && arr[i].s >= ans){
            ans ++;
            z--;
        }
    }
    return ans >= mid;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        cin >> n;
        rp(i,0,n) cin >> arr[i].f >> arr[i].s;

        int low = 1, high = n;

        while(high - low > 1){
            int mid = (low + high) / 2;
            if(check(mid)){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }

        if(check(high)) cout << high << "\n";
        else cout << low << "\n";

    }

    return 0;}