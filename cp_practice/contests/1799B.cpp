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

        vector<pii> a;

        rp(i,0,n){
            int x;
            cin >> x;
            a.pb({x,i+1});
        }

        vector<pii> ans;
        sort(all(a));

        bool check = true;  

        while(a[0].f!=a[n-1].f){
            vector<pii> b;
            int x = a[0].f,y = a[0].s;
            if(x==1){
                if(a[n-1].f!=1){
                    check = false;
                }
                break;
            }
            for(auto i : a){
                if(i.f==x){
                    b.pb({i.f,i.s});
                }
                else{
                    int z = (int)(ceil((double(i.f)/x)));
                    b.pb({z,i.s});
                    ans.pb({i.s,y});
                }
            }
            a.clear();
            for(auto i : b){
                a.pb(i);
            }
            sort(all(a));
        }

        if(check){
            cout << sz(ans) << "\n";
            for(auto i : ans){
                cout << i.f << " " << i.s << "\n";
            }
        }
        else{
            cout << "-1\n";
        }
    }

    return 0;}