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

        ll prefix_sum[n + 1] = {0};

        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            prefix_sum[i] = prefix_sum[i - 1] + a;
        }

        if (prefix_sum[n] != 0)
        {
            cout << "NO\n";
            continue;
        }
        bool ans = true,zero = false;
        for (int i = 1; i <= n; i++)
        {
            if (prefix_sum[i] < 0)
            {
                ans = false;
                break;
            }
            if(prefix_sum[i] == 0){
                while(i<=n){
                    if(prefix_sum[i]!=0){
                        ans = false;
                    }
                        ++i;
                }
            }
        }

        
        ans ? cout << "YES\n":cout<<"NO\n";
    }
    return 0;
}