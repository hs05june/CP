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

int cnt[550];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    rp(i,0,512){
        cnt[i] = -1;
    }

    int n;
    cin >> n;

    int arr[n+1];
    arr[0] = 0;
    rp(i,1,n+1){
        cin >> arr[i];
    }

    cnt[0] = 0;

    rp(i,1,n+1){
        rp(j,0,512){
            if(cnt[j] != -1 && cnt[j] < arr[i]){
                int x = j ^ arr[i];
                if(cnt[x] == -1) cnt[x] = arr[i];
                else cnt[x] = min(cnt[x],arr[i]);
            }
        }
    }

    deq ans;

    rp(i,0,512){
        if(cnt[i] != -1) ans.pb(i);
    }

    cout << sz(ans) << "\n";
    for(auto i : ans) cout << i << " ";
    cout << "\n";

    return 0;}