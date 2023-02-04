//  ੴ  ਵਾਹਿਗੁਰੂ

#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define f first
#define s second
#define lb(a, b, c) lower_bound(a, b, c)
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
const ll M = 1000000007;
using namespace std;

int power(int a, int b, int mod)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans % mod * 1LL * a % mod) % mod;
        }
        a = (a % mod * 1LL * a % mod) % mod;
        b >>= 1;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int a[n+1] = {0};
        for(int i = 1; i <= n; i++)cin >> a[i];
        
        map<int,deq> cnt;

        for(int i = 0; i <= (n+1) ; i++){
            deq d;
            d.clear();
            cnt[i] = d;
        }

        for(int i = 1; i <= n; i++){
            cnt[a[i]].pb(i);
        }

        set<int> filled;

        for(int i = 0; i <= (n+1); i++){
            if(!cnt[i].empty()){
                filled.insert(i);
            }
        }
        
        deq ans;   

            ll maxi = 1;
            ll mex = 0;
        while(filled.size()>0){
            for(int i = 0; i <= (n+1); i++){
                if(cnt[i].empty()){
                    mex = i;
                    auto itr = filled.find(i);
                    if(itr!=filled.end())filled.erase(itr);
                    break;
                }
                else{
                    maxi = max(maxi,cnt[i].front());
                }
            }
            if(mex!=0){
                for(int i = 0; i<mex;i++){
                    while(!cnt[i].empty() && cnt[i].front() <= maxi){
                        cnt[i].pop_front();
                    }
                    if(cnt[i].empty()){
                        auto itr = filled.find(i);
                        if(itr!=filled.end())filled.erase(itr);
                    }
                }
                maxi++;
                ans.pb(mex);
            }
            else{
                for(int i = 0; i <= (n-maxi); i++){
                    ans.pb(0);
                }
                break;
            }
        }

        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++)cout << ans[i] << " ";
        cout << "\n";

    }

    return 0;
}