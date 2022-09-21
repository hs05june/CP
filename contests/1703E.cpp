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

        string a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int arr[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = a[i][j] - '0';
            }
        }

        int visited[n][n] = {0};

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0)
                {
                    visited[i][j] = 1;
                    visited[j][n - 1 - i] = 1;
                    visited[n - 1 - i][n - 1 - j] = 1;
                    visited[n - 1 - j][i] = 1;

                    int cnt[2] = {0, 0};
                    cnt[arr[i][j]]++;
                    cnt[arr[j][n - 1 - i]]++;
                    cnt[arr[n - 1 - i][n - 1 - j]]++;
                    cnt[arr[n - 1 - j][i]]++;

                    ans += min(cnt[0], cnt[1]);
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}