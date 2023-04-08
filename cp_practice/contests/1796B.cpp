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

        string a,b;
        cin >> a >> b;

        if(a[a.length()-1] == b[b.length()-1]){
            cout << "YES\n";
            cout << "*" << a[a.length()-1] << "\n";
            continue;
        }

        if(a[0]==b[0]){
            cout << "YES\n";
            cout << a[0] << "*\n";
            continue;
        }

        bool check = false;
        int x,y;
        rp(i,0,a.length()-1){
            if(check)break;
            rp(j,0,b.length()-1){
                if(a[i]==b[j] && a[i+1]==b[j+1]){
                    check = true;
                    x = j; y = j+1;
                    break;
                }
            }
        }

        if(check){
            cout << "YES\n";
            cout << "*" << b[x] << b[y] << "*\n";
            continue;
        }
        cout << "NO\n";

    }

    return 0;}