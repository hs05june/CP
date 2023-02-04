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
int all_facts[11];

ll fact(int n){
    if(all_facts[n]!=-1)return all_facts[n];
    if(n==0 || n==1)return 1;
    return all_facts[n] = n * fact(n-1);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;
    memset(all_facts,-1,sizeof(all_facts));
    while(t--){

        int n;
        cin >> n;

        int arr[n];

        for(int i=0;i<n;i++)cin >> arr[i];

        ll x = 10 - n;

        cout << ((fact(x)/fact(x-2))*3) << "\n";

    }

    return 0;}