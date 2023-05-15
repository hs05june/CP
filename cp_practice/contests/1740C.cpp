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

        int n;
        cin >> n;

        int arr[n];
        set<int> uniq;
        rp(i,0,n){cin >> arr[i];uniq.insert(arr[i]);}

        if(uniq.size()==1){
            cout << "0\n";
            continue;
        }
        if(uniq.size()==2){
            cout << 2*abs(*(uniq.begin()) - *(--uniq.end())) << "\n";
            continue;
        }

        // if(uniq.size()==3){
        //     int a[3];
        //     int x = 0;
        //     for(auto i : uniq){
        //         a[x] = i;
        //         ++x;
        //     }
        //     cout << a[1] - a[0] + a[2] - a[0] << "\n";
        //     continue;
        // }

        deq a;
        for(auto i : uniq){
            a.pb(i);
        }

        int ans = 0;

        rp(i,1,sz(a)-1){
            ans = max(ans,abs(a[i]-a[i-1])+abs(a[i]-a[i+1]));
        }

        rp(i,0,sz(a)-2){
            ans = max(ans,abs(a[i]-a[i+1])+abs(a[i]-a[sz(a)-1]));
        }

        rp(i,2,sz(a)){
            ans = max(ans,abs(a[i]-a[i-1])+abs(a[i]-a[0]));
        }
        cout << ans << "\n";
    }

    return 0;}