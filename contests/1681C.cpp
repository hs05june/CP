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
        int arr[n], brr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
        }

            deque<pii> ans;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        ans.push_back({i + 1, j + 1});
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                        temp = brr[i];
                        brr[i] = brr[j];
                        brr[j] = temp;
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (brr[i] > brr[j])
                    {
                        ans.push_back({i + 1, j + 1});
                        int temp = brr[i];
                        brr[i] = brr[j];
                        brr[j] = temp;
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }

            bool check = true;

            if(check){for(int i = 0; i < n-1; i++){
                if(arr[i]>arr[i+1]){
                    check = false;
                    break;
                }
            }}

            if(check){
                for(int i = 0; i < n-1; i++){
                    if(brr[i]>brr[i+1]){
                        check = false;
                        break;
                    }
                }
            }

            if(!check){
                cout<<"-1\n";
                continue;
            }

            cout << ans.size() << "\n";
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i].first << " " << ans[i].second << "\n";
            }
       
    }
    return 0;
}