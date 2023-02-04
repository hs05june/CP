//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
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

// int dp[200007],arr[200007],covered[200007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){
    
        int n;
        cin >> n;
        string a;
        cin >> a;
        deq arr(n,0);

        for(int i=0; i<n; i++)cin >> arr[i];
        ll ans = 0;
 

        deque<pair<pii,int>> seq;

        rp(i,0,a.length()){
            if(a[i]=='1'){
                int z = i;
                int sum = 0;
                while(i<a.length() && a[i]=='1'){
                    sum+=arr[i];
                    ++i;
                }
                // --i;
                seq.pb({{z,i},sum});
            }
        }  

        // rp(i,0,seq.size()){
        //     cout << seq[i].f.f << " " << seq[i].f.s << " " << seq[i].s << "\n";
        // }

        rp(i,0,seq.size()){
            if(seq[i].f.f!=0){
                sort(arr.begin()+seq[i].f.f,arr.begin()+seq[i].f.s);
                if(arr[seq[i].f.f-1]>arr[seq[i].f.f]){
                    ans+=(seq[i].s + arr[seq[i].f.f-1]-arr[seq[i].f.f]);
                }
                else{
                    ans+=seq[i].s;
                }
            }
            else{
                    ans+=seq[i].s;
            }
        }

        cout << ans << endl;

    }

    return 0;}