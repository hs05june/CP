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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int arr[n];
        rp(i,0,n)cin >> arr[i];

        ll ans = 0, value = arr[0];
        rp(i,1,n){
            ans += abs(arr[i]-arr[i-1]);
            if(arr[i] < arr[i-1]){
                value -= (arr[i-1]-arr[i]);
            }
        }        
        cout << ans + abs(value) << "\n";
    }

    return 0;}