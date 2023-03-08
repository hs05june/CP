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
const ll M = 998244353;
using namespace std;

deq primes;
int visited[((int)sqrtl(M)) + 1], lpf[((int)sqrtl(M)) + 1];

void seive()
{

    for (int i = 2; i <= sqrtl(M); i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            primes.pb(i);
            for (int j = i; j <= sqrtl(M); j += i)
            {
                visited[j] = 1;
                lpf[j] = i;
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

    seive();

    int t = 1;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        int arr[n];

        rp(i, 0, n) cin >> arr[i];

        bool ans = true;

        rp(i, 1, n)
        {
            if ((arr[i - 1] % arr[i]) != 0)
            {
                ans = false;
            }
        }

        if (!ans)
        {
            cout << "0\n";
            continue;
        }

        int ans1 = 1;
        rp(i, 1, n)
        {
            if (arr[i - 1] == arr[i])
            {
                int z = m / arr[i];
                ans1 = ((ans1 % M) * (z % M)) % M;
                continue;
            }
            int ratio = arr[i - 1] / arr[i];
            mii cnt, cnt1;

            if (ratio > sqrtl(M))
            {
                for (auto k : primes)
                {
                    if ((ratio % k) == 0)
                    {
                        while (ratio % k == 0)
                        {
                            cnt[k]++;
                            ratio /= k;
                        }
                    }
                    if (ratio <= sqrt(M))
                    {
                        break;
                    }
                }
            }

            if (ratio != 1)
            {
                if (ratio > sqrtl(M))
                {
                    cnt[ratio]++;
                }
                else
                {
                    while (ratio != 1)
                    {
                        int rt = lpf[ratio];
                        while ((ratio % rt) == 0)
                        {
                            cnt[rt]++;
                            ratio /= rt;
                        }
                    }
                }
            }

            deq worked;
            for (auto k : cnt)
            {
                worked.pb(k.f);
                ṭ
            }
            int num = 0;
            int l = 1;

            while (l < (1 << (sz(worked))))
            {
                int j = 0, pop = 0;
                int to_do = 1;
                while ((1 << j) <= (l))
                {
                    if (((1 << j) & (l)) != 0)
                    {
                        to_do *= (worked[j]);
                        pop++;
                    }
                    if (to_do > m)
                        break;
                    ++j;
                }
                if (to_do > m)
                    break;
                if ((to_do * arr[i]) > m)
                    break;
                if (pop & 1)
                {
                    num += (m / (to_do * arr[i]));
                }
                else
                {
                    num -= (m / (to_do * arr[i]));
                }
                ++l;
            }
            int to_do = ((m / arr[i]) - num);
            ans1 = ((ans1 % M) * (to_do % M)) % M;
        }

        cout << ans1 << "\n";
    }

    return 0;
}