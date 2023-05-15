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
    // cin >> t;

    while(t--){

        int n,q;
        cin >> n >> q;

        int arr[n+1], preffix[n+1], flag[n+1];
        preffix[0] = arr[0] = flag[0] = 0;

        rp(i,1,n+1)cin >> arr[i];

        rp(i,1,n+1){
            if(arr[i]>arr[i-1]){
                flag[i] = 1;
            }
            else{
                if(i==n || arr[i+1]>arr[i])flag[i] = 1;
                else flag[i] = 0;
            }
        }

        rp(i,1,n+1)preffix[i] = preffix[i-1] + flag[i];

        while(q--){
            int a,b;
            cin >> a >> b;

            int ans = preffix[b] - preffix[a-1];
            if(b-a+1<=2){
                cout << b-a+1 << "\n";
                continue;
            }
            if(flag[a]==0)ans++;
            if(flag[b]==0)ans++;
            cout << ans << "\n";
        }        
    }

    return 0;}