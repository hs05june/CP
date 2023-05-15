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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    // cout << fixed << setprecision(20);

    int x, n;
    cin >> x >> n;

    int arr[n];
    rp(i,0,n)cin >> arr[i];

    mii cnt;
    cnt[x] = 1;
    set<int> ans;
    ans.insert(x);

    set<int> s1,s2;
    s1.insert(-x);s1.insert(0);
    s2.insert(0);s2.insert(x);
    rp(i,0,n){
        auto itr1 = s1.lower_bound(-arr[i]);
        auto itr2 = s2.lower_bound(arr[i]);
        int x = -(*itr1), y = *itr2;
        cnt[y-x]--;
        if(cnt[y-x]==0){
            ans.erase(y-x);
        }
        cnt[y-arr[i]]++;
        if(cnt[y-arr[i]]==1)ans.insert(y-arr[i]);
        cnt[arr[i]-x]++;
        if(cnt[arr[i]-x]==1)ans.insert(arr[i]-x);
        s1.insert(-arr[i]);
        s2.insert(arr[i]);
        cout << *(--ans.end()) << " ";
    }
    cout << "\n";

    return 0;}