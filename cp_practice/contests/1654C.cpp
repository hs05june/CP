#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0); cout.tie(0);
#define HARPREET cout << fixed << setprecision(20);
int M = 1000000007;
using namespace std;


signed main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        ll n;
        cin >> n;

        ll a[n];
        bool all_one = true;

        multiset<ll> all_values;
        map<ll, ll> quant;

        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            quant[a[i]]++;
        }

        if (n == 1)
        {
            cout << "YES\n";
            continue;
        }

        ll siz = n;
        all_values.insert(sum);

        while (!all_values.empty() && all_values.size() < siz)
        {
            ll x = *all_values.begin();
            all_values.erase(all_values.begin());
            ll y, z;

            if (x % 2 == 0)
            {
                y = x / 2;
                z = x / 2;
            }
            else
            {
                y = x / 2;
                z = x / 2 + 1;
            }
            bool insertz = true, inserty = true;
            if (quant[z] > 0)
            {
                quant[z]--;
                siz--;
                insertz = false;
            }
            if (quant[y] > 0)
            {
                quant[y]--;
                siz--;
                inserty = false;
            }
            if (insertz)
                all_values.insert(z);
            if (inserty)
                all_values.insert(y);
        }

        siz == 0 ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}