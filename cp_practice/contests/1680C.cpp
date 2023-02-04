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

int pre[200007];
vector<int> ones;

bool solve(int n){
    for(int i = 0; i + n <= ones.size(); i++){
        int x = ones[i];
        int
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        string a;
        cin >> a;

        rep(i,0,a.size()){
            pre[i] = 0;
        }

        ones.clear();

        rep(i,1,a.size()){
            pre[i] = pre[i-1] + (a[i-1]=='0');
            if(a[i-1]=='1'){
                ones.pb(i);
            }
        }

        // int i = 0,j=n-1;

        // while(i<n && a[i]=='0'){
        //     ++i;
        // }

        // if(i==n){
        //     cout << "0\n";
        //     continue;
        // }

        // while(j>=0 && a[j]=='0'){
        //     --j;
        // }

        // int cnt[2] = {0};
        // cnt[0] = 0;
        // cnt[1] = 0;

        // rep(k,i,j){
        //     cnt[a[k]-'0']++;
        // }

        // if(cnt[0]==0){
        //     cout << "0\n";
        //     continue;
        // }



    }

    return 0;}