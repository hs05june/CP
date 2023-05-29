#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
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

    int t = 1;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        map<int,multiset<int>> x1,y1,x2,y2;
        int x = 0, y = 0;
        int area = 0;
        pii a[n];
        set<int> h,w;

        rp(i, 0, n)
        {
            cin >> a[i].f >> a[i].s;
            x1[a[i].f].insert(a[i].s);
            y1[a[i].s].insert(a[i].f);
            x2[a[i].f].insert(a[i].s);
            y2[a[i].s].insert(a[i].f);
            h.insert(a[i].f);
            w.insert(a[i].s);
            area += (a[i].f*a[i].s);
            x = max(x, a[i].f);
            y = max(y, a[i].s);
        }

        set<pii> ans;
        if(area%x==0){
            int h = x, w = area/x;
            bool check = true;
            int cnt = 0;
            while(cnt < n){
                if(sz(x1[h])!=0){
                    int z = *(x1[h].begin());
                    w-=z;
                    x1[h].erase(x1[h].begin());
                    y1[z].erase(y1[z].find(h));
                }
                else if(sz(y1[w])!=0){
                    int z = *(y1[w].begin());
                    h-=z;
                    y1[w].erase(y1[w].begin());
                    x1[z].erase(x1[z].find(w));
                }
                else{
                    check = false;
                    break;
                }
                ++cnt;
            }
            if(check)ans.insert({x,area/x});
        }

        if(area%y==0){
            int h = area/y, w = y;
            bool check = true;
            int cnt = 0;
            while(cnt < n){
                if(sz(y2[w])!=0){
                    int z = *(y2[w].begin());
                    h-=z;
                    y2[w].erase(y2[w].begin());
                    x2[z].erase(x2[z].find(w));
                }
                else if(sz(x2[h])!=0){
                    int z = *(x2[h].begin());
                    w-=z;
                    x2[h].erase(x2[h].begin());
                    y2[z].erase(y2[z].find(h));
                }
                else{
                    check = false;
                    break;
                }
                ++cnt;
            }
            if(check)ans.insert({area/y,y});
        }

        cout << sz(ans) << "\n";
        for(auto i : ans)cout << i.f << ' ' << i.s << "\n";

    }

    return 0;
}