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

void decrease_cnt(int cnt[], int x, int m)
{
    for (int i = 1; i * i <= x; i++)
    {
        if ((x % i) == 0)
        {
            if (i <= m)
                cnt[i]--;
            if ((x / i) <= m && i != (x / i))
                cnt[(x / i)]--;
        }
    }
}

void increase_cnt(int cnt[], int x, int m, int &factors)
{
    for (int i = 1; i * i <= x; i++)
    {
        if ((x % i) == 0)
        {
            if (i <= m)
            {
                if (cnt[i] == 0)
                    factors++;
                cnt[i]++;
            }
            if ((x / i) <= m && i != (x / i))
            {
                if (cnt[x / i] == 0)
                    factors++;
                cnt[(x / i)]++;
            }
        }
    }
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

        int n, m;
        cin >> n >> m;
        int arr[n];

        rp(i, 0, n) cin >> arr[i];

        int cnt[m + 1];

        rp(i, 0, m + 1)
        {
            cnt[i] = 0;
        }

        sort(arr, arr + n);

        int factors = 0;

        int ans = LLONG_MAX;
        int l = 0;
        rp(r, 0, n)
        {
            increase_cnt(cnt, arr[r], m, factors);
            if (factors == m)
            {
                ans = min(arr[r] - arr[l], ans);
                while (l < r)
                {
                    bool check = true;
                    for (int i = 1; i * i <= arr[l]; i++)
                    {
                        if ((arr[l] % i) == 0)
                        {
                            if (i <= m && cnt[i] == 1)
                                check = false;
                            if ((arr[l] / i) <= m && cnt[arr[l] / i] == 1)
                                check = false;
                        }
                    }
                    if (check)
                    {
                        decrease_cnt(cnt, arr[l], m);
                        ++l;
                        ans = min(ans, arr[r] - arr[l]);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        (factors == m) ? cout << ans << "\n" : cout << "-1\n";
    }

    return 0;
}