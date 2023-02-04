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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        mii cnt;

        int a[n+1][m+1];
        rep(i,1,n){
            rep(j,1,m){
                cin >> a[i][j];
                cnt[i]+=a[i][j];
            }
        }

        int total = 0;

        for(auto i : cnt){
            total+=i.s;
        }

        int each = (total/n);
        set<int> less;

        rep(i,1,n){
            if(cnt[i]<each){
                less.insert(i);
            }
        }

        if((total%n)!=0){
            cout << "-1\n";
            continue;
        }   

        vector<int> khaali[m+1];
        vector<pair<pii,int>> ans;

        for(auto i : less){
            rp(j,1,m){
                if(a[i][j]==0){
                    khaali[j].pb(i);
                }
            }
        }

        rep(i,1,n){
            if(cnt[i]>each){
                rp(j,1,m){
                    if(cnt[i]<=each)break;
                    if(a[i][j]==0)continue;
                    int z = 0;
                    while(khaali[j].size()>0 && z==0){
                        if(cnt[(khaali[j].back())]<each){
                            z = khaali[j].back();
                        }
                        khaali[j].pop_back();
                    }
                    if(z!=0){cnt[z]++;
                    cnt[i]--;
                    a[z][j] = 1;
                    a[i][j] = 0;
                    if(cnt[z]>=each)less.erase(z);
                    ans.pb({{i,z},j});}
                }
            }
        }
        cout << sz(ans) << "\n";
        for(auto i : ans){
            cout << i.f.f << " " << i.f.s << " " << i.s << "\n";
        }

    }

    return 0;}