#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
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

        int prev;
        cout << "? 1 2 3" << endl;
        cin >> prev;

        int z1 = -1, z2 = -1;

        rp(i,4,n+1){
            int z;
            cout << "? " << i-2 << " " << i-1 << " " << i << endl;
            cin >> z;
            if(z != prev){
                z1 = i, z2 = i-3;
                if(z == 1){
                    swap(z1,z2);
                }
                break;
            }
            prev = z;
        }

        deq ans;
        ans.pb(z1);

        rp(i,1,n+1){
            if(i == z1 || i == z2)continue;
            int z;
            cout << "? " << i << " " << z1 << " " << z2 << endl;
            cin >> z;
            if(z == 0)ans.pb(i);
        }

        cout << "! " << sz(ans) << " ";
        for(auto i : ans)cout << i << " ";
        cout << endl;

    }

    return 0;}