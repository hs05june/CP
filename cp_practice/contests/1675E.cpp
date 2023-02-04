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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;

        string a;
        cin >> a;

        // deque<pair<char,ll>> str;        
        // for(int i = 0; i < a.length(); i++){
        //     str.pb({a[i],i});
        // }

        // sort(all(str));

        ll to = 0,prev = -1;
        
        for(int i = 0; i < a.length(); i++){
            if((int)(a[i]-'a')<=k){
                to = max(to,(int)(a[i]-'a'));
                prev = i;
            }
            else{
                break;
            }
        }

        k-=to;
        char z = 'a' + to;
        for(int i = 0; i < n; i++){
            if(a[i]<=z)a[i] = 'a';
        }
        char x,y;
        if((prev+1)!=n){
            y = a[prev+1];
            x = char(y - k);

            for(int i = 0; i < n; i++){
                if(a[i]>=x && a[i]<=y){
                    a[i] = x;
                }
            }
        }

        cout << a << "\n";
    }

    return 0;}