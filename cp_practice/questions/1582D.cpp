#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define ld long double
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

        int n;
        cin >> n;

        ll arr[n];
        rp(i, 0, n) cin >> arr[i];

        ll ans[n] = {0};

        if (n % 2 == 0)
        {
            for(int i = 0; i < n; i+=2){
                ans[i] = abs(arr[i+1]);
                ans[i+1] = abs(arr[i]);
                if((arr[i]<0) == (arr[i+1]<0)) ans[i]*=(-1);
            }
        }
        else{
            int x = -1;
            deq fill;
            rp(i,1,n){
                if(arr[i]+arr[0] != 0){
                    x = i;
                    break;
                }
            }
            if(x != -1){
                int y = (x==1) ? 2 : 1;
                ans[0] = abs(arr[y]);
                ans[x] = abs(arr[y]);
                ans[y] = abs(arr[0]+arr[x]);
                if(((arr[0]+arr[x]) < 0) == (arr[y] < 0)) ans[y]*=(-1);
                rp(i,1,n){
                    if(i!=x && i!=y)fill.pb(i);
                }
            }
            else{
                rp(i,0,n){
                    if(i==1)continue;
                    if(arr[i]+arr[1] != 0){
                        x = i;
                        break;
                    }
                }
                int y = (x==0) ? 2 : 0;
                ans[1] = abs(arr[y]);
                ans[x] = abs(arr[y]);
                ans[y] = abs(arr[x]+arr[1]);
                if(((arr[1]+arr[x]) < 0) == (arr[y] < 0)) ans[y]*=(-1);
                rp(i,0,n){
                    if(i!=x && i!=y && i!=1)fill.pb(i);
                }
            }
            for(int i = 0; i < sz(fill); i+=2){
                ans[fill[i]] = abs(arr[fill[i+1]]);
                ans[fill[i+1]] = abs(arr[fill[i]]);
                if((arr[fill[i]]<0) == (arr[fill[i+1]]<0)) ans[fill[i]]*=(-1);
            }
        }
        rp(i,0,n) cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}