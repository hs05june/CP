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

    int n, x;
    cin >> n >> x;

    int arr[n+1], preffix[n+1];
    arr[0] = preffix[0] = 0;

    rp(i,1,n+1)cin >> arr[i];
    rp(i,1,n+1)preffix[i] = arr[i] + preffix[i-1];

    mii cnt;
    rp(i,1,n+1)cnt[preffix[i]]++;

    int ans = 0;

    rp(i,1,n+1){
        ans+=cnt[x];
        x+=arr[i];
        cnt[preffix[i]]--;
    }

    cout << ans << "\n";

    return 0;}