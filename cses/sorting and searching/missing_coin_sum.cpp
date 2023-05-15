#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
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

    int n;
    cin >> n;

    int arr[n],sum = 0;

    rp(i,0,n){cin >> arr[i];sum+=arr[i];}

    sort(arr,arr+n);

    if(arr[0]!=1){
        cout << "1\n";
        return 0;
    }

    int maxi = 1;
    
    rp(i,1,n){
        if(arr[i] > 1 + maxi){
            cout << 1+maxi << "\n";
            return 0;
        }
        maxi+=arr[i];
    }

    cout << sum+1 << "\n";

    return 0;
}