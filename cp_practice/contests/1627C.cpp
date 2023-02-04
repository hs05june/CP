//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define lb(a,b,c) lower_bound(a,b,c)
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
const ll M = 1000000007;
using namespace std;

deque<pii> graph[100007];
deq dfs_ans;

int power(int a, int b, int mod)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans % mod * 1LL * a % mod) % mod;
        }
        a = (a % mod * 1LL * a % mod) % mod;
        b >>= 1;
    }
    return ans;
}

void dfs(int root, int prev)
{
    dfs_ans.push_back(root);
    if (graph[root].size() == 1 && graph[root][0].f == prev)
    {
        return;
    }

    ll new_root = graph[root][0].f == prev ? graph[root][1].f : graph[root][0].f;
    dfs(new_root, root);
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

        int n;
        cin >> n;
        dfs_ans.clear();
        rep(i, 0, n)
        {
            graph[i].clear();
        }

        deque<pii> question;

        rp(i, 1, n)
        {
            ll x, y;
            cin >> x >> y;
            question.pb({x, y});
            graph[x].pb({y, 0});
            graph[y].pb({x, 0});
        }

        bool ans = true;

        rep(i, 1, n)
        {
            if (graph[i].size() >= 3)
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

        ll root = 0;

        rep(i, 1, n)
        {
            if (graph[i].size() == 1)
            {
                root = i;
                break;
            }
        }

        dfs(root, 0);
        ll x = 2;
        rp(i, 0, dfs_ans.size() - 1)
        {
            if (graph[dfs_ans[i]][0].f == dfs_ans[i + 1])
            {
                graph[dfs_ans[i]][0].s = x;
                if (graph[dfs_ans[i + 1]][0].f == dfs_ans[i])
                {
                    graph[dfs_ans[i + 1]][0].s = x;
                }
                else
                {
                    graph[dfs_ans[i + 1]][1].s = x;
                }
                x = x == 2 ? 3 : 2;
            }
            else
            {
                graph[dfs_ans[i]][1].s = x;
                if (graph[dfs_ans[i + 1]][0].f == dfs_ans[i])
                {
                    graph[dfs_ans[i + 1]][0].s = x;
                }
                else
                {
                    graph[dfs_ans[i + 1]][1].s = x;
                }
                x = (x == 2) ? 3 : 2;
            }
        }
        rp(i, 0, question.size())
        {
            ll x = question[i].f, y = question[i].s;
            if (graph[x].size() == 1)
            {
                cout << graph[x][0].s << " ";
            }
            else
            {
                graph[x][0].f == y ? cout << graph[x][0].s << " " : cout << graph[x][1].s << " ";
            }
        }
    }

    return 0;
}