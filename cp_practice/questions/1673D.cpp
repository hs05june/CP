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

        int a1,d1,n1;
        int a2,d2,n2;
        cin >> a1 >> d1 >> n1;
        cin >> a2 >> d2 >> n2;
        int l2 = a2 + (n2-1)*d2, l1 = a1 + (n1-1)*d1;

        if((d2%d1) != 0 || ((a2-a1)%d1) != 0 || (((a2-a1) / d1) + 1) <= 0 || (l2 > l1)){
            cout << "0\n";
            continue;
        }

        if((a2 - d2) < a1 || (l2 + d2) > l1){
            cout << "-1\n";
            continue;
        }

        int ans = 0;

        for(int i = 1; i * i <= d2; i++){
            if(d2%i==0){
                int f1 = i, f2 = d2/i;
                if(((f1*d1)/__gcd(f1,d1))==d2){
                    int x = d2/f1;
                    int y  = (x%M * x%M)%M;
                    ans = (ans%M + y%M)%M;
                }
                if(f1!=f2 && ((f2*d1)/__gcd(f2,d1))==d2){
                    int x = d2/f2;
                    int y = (x%M * x%M)%M;
                    ans = (ans%M + y%M)%M;
                }
            }
        }

        cout << ans << "\n";

    }

    return 0;}