//							  ੴ  ਵਾਹਿਗੁਰੂ

#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
#define int long long
#define deq deque<ll>
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

void solve(int a,int b,string t,string s[],int n,deque<pii> ans1){
    for(int i = a; i <= b;i++){
        rp(j,0,n){
            if((i+s[j].length())>t.length() || (i+s[j].length())<=b)continue;
            
        }
    }
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

        string a;
        cin >> a;

        int n;
        cin >> n;

        string b[n];

        rp(i, 0, n)
        {
            cin >> b[i];
        }

        int visited[n] = {0};
        deque<pii> possible;

        rp(i, 0, a.length())
        {
            rp(j, 0, n)
            {
                bool used = true;
                rp(k, 0, b[j].length())
                {
                    if (a[k + i] != b[j][k])
                    {
                        used = false;
                        break;
                    }
                }
                if (used)
                {
                    rp(k, 0, b[j].length())
                    {
                        visited[i + k] = 1;
                    }
                }
            }
        }

        bool ans = true;

        rp(i, 0, a.length())
        {
            if (visited[i] == 0)
            {
                ans = false;
                break;
            }
        }

        if (!ans)
        {
            cout << "-1\n";
            continue;
        }

        deque<pii> ans1;
        solve(0,0,a,b,n,ans1);

        cout << ans1.size() << "\n";
        for(auto i : ans1){
            cout << i.f << " " << i.s << "\n";
        }
        
    }
    return 0;
}