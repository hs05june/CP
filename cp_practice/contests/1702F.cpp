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

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        mii a;
        multiset<int> b;

        rp(i,0,n){
            int x;
            cin >> x;
            while(x%2==0){
                x/=2;
            } 
            a[x]++;
        }       
        
        rp(i,0,n){
            int x;
            cin >> x;
            b.insert(x);
        }

        bool ans = true;

        while(b.size()>0){
            int x = *(--b.end());
            bool found = false;
            while(x>0){
                if(a[x]>0){
                    found = true;
                    a[x]--;
                    break;
                }
                x/=2;
            }
            if(!found){ans = false;break;}
            if(found){
                b.erase((--b.end()));
            }
        }

        ans ? cout << "Yes\n" : cout << "No\n";

    }

    return 0;}