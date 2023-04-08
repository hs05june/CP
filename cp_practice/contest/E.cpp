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

        int n,k;
        cin >> n >> k;

        string a[n],b[n];
        rp(i,0,n)cin >> a[i];
        rp(i,0,n)cin >> b[i];

        int cnta[26], cntb[26];
        int lena[20],lenb[20];

        rp(i,0,26){
            cnta[i] = cntb[i] = 0;
        }

        // rp(i,0,20){
        //     lena[i] = lenb[i] = 0;
        // }

        bool check = true;
        rp(i,0,n){
            // lena[sz(a[i])]++;
            // lenb[sz(b[i])]++;
            if(sz(a[i])!=sz(b[i])){
                check = false;
            }
            for(auto j : a[i]){
                cnta[(int)(j-'0')]++;
            }
            for(auto j : b[i]){
                cntb[(int)(j-'0')]++;
            }
        }


        // rp(i,0,20){
        //     if(lena[i]!=lenb[i])check = false;
        // }

        if(!check){
            cout << "NO\n";
            continue;
        }

        int cost = 0;

        rp(i,0,26){
            cost+=abs(cnta[i]-cntb[i]);
        }

        cost/=2;

        cost<=k ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;}