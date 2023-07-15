#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define ld long double
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

bool check(pii segment[], int query[], int n, int m, int mid){
    int preffix[m+1];
    rp(i,0,m+1) preffix[i] = 0;

    rp(i,0,mid){
        preffix[query[i]]++;
    }

    rp(i,1,m+1)preffix[i] += preffix[i-1];

    rp(i,0,n){
        int ones = preffix[segment[i].s] - preffix[segment[i].f-1];
        int y = segment[i].s - segment[i].f + 1;
        int zeros = y - ones;
        if(ones > zeros)return true;
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> m >> n;
        pii segment[n];

        rp(i, 0, n)
        {
            cin >> segment[i].f >> segment[i].s;
        }

        int q;
        cin >> q;

        int query[q];

        rp(i, 0, q)
        {
            cin >> query[i];
        }

        int low = 1, high = q;

        while(high - low > 1){
            int mid = (low+high) / 2;
            if(check(segment,query,n,m,mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        if(check(segment,query,n,m,low))cout << low << "\n";
        else if(check(segment,query,n,m,high))cout << high << "\n";
        else cout << "-1\n";

    }

    return 0;
}