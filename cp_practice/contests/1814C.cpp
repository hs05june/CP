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

        int n,s1,s2;
        cin >> n >> s1 >> s2;

        pii arr[n];

        rp(i,0,n){
            cin >> arr[i].f;
            arr[i].s = i+1;
        }

        sort(arr,arr+n);
        reverse(arr,arr+n);

        deq a,b;

        rp(i,0,n){
            int x1 = s1*(a.size()+1);
            int x2 = s2*(b.size()+1);
            if(x1<=x2){
                a.pb(arr[i].s);
            }
            else{
                b.pb(arr[i].s);
            }
        }

        cout << sz(a) << " ";
        for(auto i : a)cout << i << " ";
        cout << "\n";
        cout << sz(b) << " ";
        for(auto i : b)cout << i << " ";
        cout << "\n";
    }

    return 0;}