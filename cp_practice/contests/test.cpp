#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1] = {0};
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        set<int> s, s1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s1.count(a[i]) || (a[i] < a[i - 1]))
            {
                for (auto j : s)
                    s1.insert(j);
                s.clear();
            }
            s.insert(a[i]);
        }
        cout << s1.size() << "\n";
    }
    return 0;
}