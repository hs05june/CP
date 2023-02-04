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

        int n;
        cin >> n;

        string a,b;
        cin >> a >> b;

        bool persist = true;
        bool check = true;
        if(a[0]!=b[0])persist=false;

        rp(i,0,n){
            if(persist){
                if(a[i]!=b[i])check=false;
            }
            else{
                if(a[i]==b[i])check=false;
            }
        }

        if(!check){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<pii> ans;
        if(!persist){
            ans.pb({1,n});
        }

        rp(i,0,n){
            if(b[i]=='1'){
                if(i==0){
                    ans.pb({i+2,n});
                    ans.pb({i+1,n});
                }
                else{
                    int x = i;
                    while(i<n && b[i]=='1'){
                        ++i;
                    }
                    --i;
                    int y = i;
                    ans.pb({1,x});
                    ans.pb({1,y+1});
                }
            }
        }

        cout << sz(ans) << "\n";
        for(auto i : ans){
            cout << i .f << " " << i.s << "\n";
        }
    }

    return 0;}