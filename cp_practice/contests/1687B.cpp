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
    // cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        set<pii> edges;

        int x = 0;

        while(x<m){
            string a = "";
            rp(i,0,m){
                if(i==x){
                    a.pb('1');
                }
                else{
                    a.pb('0');
                }
            }
            cout << "? " << a << endl;
            int z;
            cin >> z;
            edges.insert({z,x});
            ++x;
        }

        int ans = 0;
        set<int> done;

        string z = "";
        rp(i,0,m){
            z.pb('0');
        }

        for(auto i : edges){
            int x = i.f,y = i.s;
            string check = z;
            rp(i,0,m){
                if(i==y){
                    check[i] = '1';
                }
            }
            cout << "? " << check << endl;
            int h;
            cin >> h;
            if(h==ans+x){
                z = check;
                ans+=x;
            }
        }

        cout << "! " << ans << endl;

    }

    return 0;}