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

        int a[n];

        int zero = n-1, one = 0;

        rp(i,0,n){
            cin >> a[i];
        }

        rp(i,0,n){
            if(a[i]==1){
                one = i;
            }
            if(a[n-1-i]==0){
                zero = n-1-i;
            }
        }

        int ans1 = 0,ans2 = 0,ans3 = 0,cnt = 0;
        rp(i,0,n){
            if(a[i]==1){
                cnt++;
            }
            if(a[i]==0){
                ans3+=cnt;
            }
        }
        cnt=0;
        if(one!=0){a[one] = 0;
        rp(i,0,n){
            if(a[i]==1)cnt++;
            if(a[i]==0)ans1+=cnt;
        }
        a[one] = 1;}
        cnt = 0;
        if(zero!=n-1){a[zero] = 1;
        rp(i,0,n){
            if(a[i]==1)cnt++;
            if(a[i]==0)ans2+=cnt;
        }
        a[zero] = 0;}

        cout << max(ans1,max(ans2,ans3)) << "\n";
    }

    return 0;}