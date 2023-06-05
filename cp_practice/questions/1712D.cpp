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
const ll M = 1000000000;
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){
        
        int n,k;
        cin >> n >> k;
        
        set<pii> some;

        int arr[n];
        rp(i,0,n){
            cin >> arr[i];
            some.insert({arr[i],i});
        }

        if(k==n){
            cout << M << "\n";
            continue;
        }
        
        int x = 0;

        int ans = 0;
        for(auto i : some){
            if(x==k)break;
            arr[i.s] = M;
            ++x;
        }

        int mini = LLONG_MAX;

        rp(i,0,n)mini = min(mini,arr[i]);

        rp(i,0,n-1){
            ans = max(ans,min(2*mini,min(arr[i],arr[i+1])));
        }
        int mini1, ind;
        x = 0;
        for(auto i : some){
            if(x==(k-1)){
                mini = i.f;
                ind = i.s;
            }
            if(x==k){
                mini1 = i.f;
            }
            ++x;
        }
        arr[ind] = mini;
        rp(i,0,n-1){
            if(i!=ind){
                ans = max(ans,min(2*mini,min(M,arr[i+1])));
            }
            if(i+1!=ind){
                ans = max(ans,min(2*mini,min(M,arr[i])));
            }
            if(i==ind){
                ans = max(ans,min(2*mini1,min(M,arr[i+1])));
            }
            if((i+1)==ind){
                ans = max(ans,min(2*mini1,min(M,arr[i])));
            }
        }
        cout << ans << "\n";
    }

    return 0;}