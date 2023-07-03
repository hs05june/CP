#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define int long long
#define ld long double
#define deq vector<ll>
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

int cnt[200007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n];
        deq index[n+1];

        rp(i,0,n){
            cin >> arr[i];
            index[arr[i]].pb(i);
            cnt[arr[i]]++;
        }

        set<pii> q;
        int ans[n];

        rp(i,0,n)q.insert({-cnt[arr[i]],arr[i]});

        auto itr = q.begin();
        auto itr1 = q.begin();
        ++itr1;
        int x = (*itr).s;

        while(itr!=q.end()){
            int y = (*itr).s;
            int z = -(*itr).f;
            if(itr1!=q.end()){
                int y1 = (*itr1).s;
                while(!index[y1].empty() && z--){
                    ans[index[y1].back()] = y;
                    index[y1].pop_back();
                }
            }
            while(!index[x].empty() && z--){
                ans[index[x].back()] = y;
                index[x].pop_back();
            }
            ++itr;
            ++itr1;
        }

        rp(i,0,n)cout << ans[i] << " ";
        cout << "\n";

        rp(i,0,n){
            cnt[arr[i]]--;
        }

    }

    return 0;}