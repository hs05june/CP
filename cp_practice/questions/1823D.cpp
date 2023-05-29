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

deq get_array(deque<int> &pre, int x)
{
    deq arr;
    int z = 0;
    while (z == pre.back() || z == pre[sz(pre) - 2])
    {
        ++z;z %= x;
    }
    arr.pb(z);
    ++z;z %= x;
    while (z == pre.back() || arr.back() == z)
    {
        ++z;z %= x;
    }
    arr.pb(z);
    ++z;z %= x;
    while (arr.back() == z || arr[0] == z)
    {
        ++z;z %= x;
    }
    arr.pb(z);
    ++z;
    z %= x;
    return arr;
}

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

        int n, k;
        cin >> n >> k;

        int len[k + 1], palin[k + 1];
        len[0] = palin[0] = 0;
        rp(i, 1, k + 1) cin >> len[i];
        rp(i, 1, k + 1) cin >> palin[i];
        bool check = true;

        rp(i, 1, k + 1)
        {
            if ((len[i] <= 3 && palin[i] != len[i]) || (len[i] - len[i - 1]) < (palin[i] - palin[i - 1]))
                check = false;
        }

        if (!check)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        if(n<=3){
            string ans = "";
            rp(i,0,n){
                ans.pb(char(i+'a'));
            }
            cout << ans << "\n";
            continue;
        }

        string ans = "abc";
        deque<int> pre;
        rp(i,0,3)pre.pb(i);
        int x = 2, index = 1;

        rp(i, 1, k + 1)
        {
            if (len[i] > 3)
            {
                index = i;
                break;
            }
        }

        len[index-1] = 3, palin[index-1] = 3;

        rp(i, index, k + 1)
        {
            int incp = palin[i] - palin[i - 1], incl = len[i] - len[i - 1];
            if (incp > 0)
            {
                ++x;
                while (incp > 0)
                {
                    ans.pb(char(x + 'a'));
                    --incp;
                    --incl;
                }
                pre.pb(x);
                if (sz(pre) > 3)
                    pre.pop_front();
            }
            deq arr = get_array(pre, x + 1);
            int y = 0;
            while (incl > 0)
            {
                ans.pb(char(arr[y] + 'a'));
                pre.pb(arr[y]);
                if (sz(pre) > 3)
                    pre.pop_front();
                ++y;
                y %= 3;
                incl--;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}