#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a, b) lower_bound((a).begin(), (a).end(), b)
const ll M = 1000000007;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while (t--)
    {

        int n, coins;
        cin >> n >> coins;

        int arr[n + 2];
        arr[0] = arr[n + 1] = 0;

        rp(i, 1, n + 1) cin >> arr[i];

        set<pii> least;
        mii include;
        rp(i,1,n+1){
            int x = min(i + arr[i], n + 1 - i + arr[i]);
            include[i] = x;
            least.insert({x,i});
        }

        deq preffix;
        preffix.pb(0);

        int k = 1;
        mii hash;

        for(auto i : least){
            hash[i.s] = k;
            preffix.pb(preffix.back() + i.f);
            ++k;
        }
        int ans = 0;
        rp(i,1,n+1){
            int x = i + arr[i];
            if(x > coins)continue;
            int c = coins - x;
            auto itr = upper_bound(all(preffix),c);
            --itr;
            int j = itr - preffix.begin();
            int ans1;
            if(hash[i]>j){
                ans1 = j + 1;
            }
            else{
                c+=include[i];
                itr = upper_bound(all(preffix),c);
                --itr;
                ans1 = (itr - preffix.begin());
            }
            ans = max(ans,ans1);
        }

        cout << ans << "\n";

    }

    return 0;
}