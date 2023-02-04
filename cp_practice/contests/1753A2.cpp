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
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n+1] = {0};
        int sum = 0;

        map<int,deq> m;
        deque<pii> ans;

        rep(i,1,n){
            cin >> a[i];
            sum+=a[i];
            m[a[i]].pb(i);
        }

        if(sum==0){
            cout << n << "\n";
            rep(i,1,n){
                cout << i << " " << i << "\n";
            }
            continue;
        }

        if((abs(sum)%2)!=0){
            cout << "-1\n";
            continue;
        }

        set<int> used;
        if(sum>0){
            int z = sum/2;
            while(z--){
                int x = m[1].back();
                m[1].pop_back();
                if(m[1].back()==(x-1)){
                    m[1].pop_back();
                }
                used.insert(x);
                used.insert(x-1);
                ans.pb({x-1,x});
            }
        }
        if(sum<0){
            int z = (abs(sum)/2);
            while(z--){
                int x = m[-1].back();
                m[-1].pop_back();
                if(m[-1].back()==(x-1)){
                    m[-1].pop_back();
                }
                used.insert(x);
                used.insert(x-1);
                ans.pb({x-1,x});
            }
        }

        rep(i,1,n){
            if(!used.count(i)){
                ans.pb({i,i});
            }
        }
        sort(ans.begin(),ans.end());
        cout << sz(ans) << "\n";
        rp(i,0,sz(ans)){
            cout << ans[i].f << " " << ans[i].s << "\n";
        }
    }

    return 0;}