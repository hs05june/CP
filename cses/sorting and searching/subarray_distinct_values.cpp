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

    int n,k;
    cin >> n >> k;
    int arr[n];
    rp(i,0,n)cin >> arr[i];
    int i = 0;
    int ans = 0;

    set<int> uniq;
    mii cnt;

    rp(j,0,n){
        uniq.insert(arr[j]);
        cnt[arr[j]]++;
        if(sz(uniq)>k){
            while(i<=j && sz(uniq)>k){
                cnt[arr[i]]--;
                if(cnt[arr[i]]==0)uniq.erase(arr[i]);
                ++i;
            }
        }
        ans+=(j-i+1);
    }

    cout << ans << "\n";

    return 0;}