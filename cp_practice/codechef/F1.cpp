#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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
int levels[300005],values[300005],visited[300005];
deq tree[300005];

int cnt[2];

void dfs(int n, int level){
    levels[n] = level;
    for(auto i : tree[n]){
        if(visited[i]==0){
            visited[i] = 1;
            dfs(i,level+1);
        }
    }
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        rep(i,0,n){
            levels[i] = 0;
            values[i] = 0;
            visited[i] = 0;
            tree[i].clear();
        }
        cnt[0] = n;
        cnt[1] = 0;

        rp(i,1,n){
            int a,b;
            cin >> a >> b;
            tree[a].pb(b);
            tree[b].pb(a);
        }

        visited[1] = 1;
        int leaf = 0;
        dfs(1,1);
        rep(i,1,n){
            leaf = max(leaf,levels[i]);
        }
        int q;
        cin >> q;

        while(q--){
            int a;
            cin >> a;
            if(a==2){
                if(values[1]==0){
                cout << n - cnt[1] - 1 << "\n";}
                else{
                    cout << n - 1 << "\n";
                }
            }
            else if(a==1){
                int b;
                cin >> b;
                int x = values[b];
                if(tree[b].size()==1){
                    values[b] = 1;
                }
                else{
                    int z = 1;
                    for(auto i : tree[b]){
                        if(levels[i]>levels[b]){
                            z = (z & values[i]);
                        }
                    }
                    values[b] = z;
                }
                if(x!=values[b]){
                    cnt[x]--;
                    cnt[(x+1)%2]++;
                }
                // rep(i,1,n){
                //     cout << values[i] << " ";
                // }
                // cout << "\n" << cnt[0] << " " << cnt[1] << "\n";
            }
        }
    }

    return 0;}