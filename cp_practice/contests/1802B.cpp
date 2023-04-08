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

        int n;
        cin >> n;

        int arr[n];

        rp(i, 0, n)
        {
            cin >> arr[i];
        }
        int maxi = 0, used = 0;
        int male = 0, female = 0, unknown = 0;

        rp(i, 0, n)
        {
            if (arr[i] == 1)
            {
                unknown++;
                maxi = max(maxi, male + female + unknown + used);
            }
            else if (arr[i] == 2)
            {
                if (unknown == 0)
                    continue;
                if (female == 0)
                {
                    female = 1;
                    unknown--;
                }

                male += unknown;
                unknown = 0;
                used += (male / 2);
                male = ((male % 2) == 0) ? 0 : 1;
                maxi = max(maxi, male + female + unknown + used);
            }
        }

        cout << maxi << "\n";
    }

    return 0;
}