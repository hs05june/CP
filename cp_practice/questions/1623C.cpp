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

ll arr[200007];

bool check(int n, ll mid){
    ll arr1[n];
    rp(i,0,n) arr1[i] = arr[i];
    rep(i,n-1,0){
        if(arr1[i] > mid){
            int donate = min(arr[i],arr1[i]-mid);
            int z = (donate / 3);
            if(i-2 >= 0){
                arr1[i-2] += (2*z);
                arr1[i-1] += z;
            }
            arr1[i] -= (3*z);
        }
    }
    bool ans = true;
    rp(i,0,n){
        if(arr1[i] < mid)ans = false;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        ll sum = 0;

        rp(i,0,n){
            cin >> arr[i];
            sum += arr[i];
        }

        ll low = 0, high = sum;

        while(high - low > 1){
            ll mid = (low+high)/2;
            if(check(n,mid)){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }

        if(check(n,high)) cout << high << "\n";
        else cout << low << "\n";

    }

    return 0;}