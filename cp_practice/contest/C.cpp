#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define int long long
#define deq vector<ll>
#define sz(a) (int)a.size()
using namespace std;

signed main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        int arr[n];
        rp(i, 0, n) cin >> arr[i];
        deq unique_array;
        unique_array.push_back(arr[0]);
        deq element;
        element.push_back(arr[0]);

        rp(i, 1, n)
        {
            if (arr[i] != element.back())
                element.push_back(arr[i]);
        }

        int answer[sz(element) + 1];

        rp(i, 1, sz(element))
        {
            if (element[i] > element[i - 1])
                answer[i] = 2;
            if (element[i] < element[i - 1])
                answer[i] = 1;
        }

        rp(i, 1, sz(element) - 1)
        {
            if (answer[i] != answer[i + 1])
                unique_array.push_back(element[i]);
        }

        if (unique_array.back() != element[sz(element) - 1])
            unique_array.push_back(element[sz(element) - 1]);

        cout << sz(unique_array) << "\n";
    }

    return 0;
}