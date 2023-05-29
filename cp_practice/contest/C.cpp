#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define int long long
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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        set<pii> check[n+1];

        rp(i,1,n){
            int a,b;
            cin >> a >> b;
            check[a].insert({i,b});
            check[b].insert({i,a});
        }

        int ans[n+1];
        rp(i,1,n+1)ans[i] = 0;
        ans[1] = 1;

        queue<pii> bfs;
        bfs.push({1,0});
        while(!bfs.empty()){
            auto x = bfs.front();
            bfs.pop();
            auto itr1 = check[x.f].lower_bound({x.s,0});
            auto itr2 = check[x.f].lower_bound({x.s,0});
            while(itr1!=check[x.f].end()){
                auto z = *itr1;
                ++itr1;
                if(ans[z.s]!=0)continue;
                ans[z.s] = ans[x.f];
                bfs.push({z.s,z.f});
            }
            auto itr = check[x.f].begin();
            while(itr!=itr2){
                auto z = *itr;
                ++itr;
                if(ans[z.s]!=0)continue;
                ans[z.s] = 1 + ans[x.f];
                bfs.push({z.s,z.f});
            }
        }

        int maxi = 0;
        ans[0] = 0;
        rp(i,1,n+1)maxi = max(maxi,ans[i]);
        // rp(i,0,n+1)cout << ans[i] << " ";
        // cout << "\n";
        cout << maxi << "\n";

    }

    return 0;}