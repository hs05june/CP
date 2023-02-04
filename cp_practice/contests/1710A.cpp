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
#define lb(a,b,c) lower_bound(a,b,c)
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
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

        int n,m,k;
        cin >> n >> m >> k;

        deq arr(k,0);

        rp(i,0,k){cin >> arr[i];}

        int l = n,h = m;

        sort(all(arr));
        reverse(all(arr));

        int cnt1[k] = {0}; 
        ll z = 0;
        for(int i = 0; i < k && l > 0; i++){
            cnt1[i] = arr[i]/m;
            l-=cnt1[i];
            z = i;
        }

        bool check1 = true;

        if(l > 0 || cnt1[z]==1){
            check1 = false;
        }
        else{
            bool three  = false;
            ll remain = n;
            for(int i = 0; i <= z;i++){
                if(cnt1[i]>=3)three = true;
                if(i!=z)remain-=cnt1[i];
            }
            if(remain==1 && !three){
                check1 = false;
            }
        }
        int cnt2[k] = {0}; 
        z = 0;
        for(int i = 0; i < k && h > 0; i++){
            cnt2[i] = arr[i]/n;
            h-=cnt2[i];
            z = i;
        }

        bool check2 = true;

        if(h > 0 || cnt2[z]==1){
            check2= false;
        }
        else{
            bool three  = false;
            ll remain = m;
            for(int i = 0; i <= z;i++){
                if(cnt2[i]>=3)three = true;
                if(i!=z)remain-=cnt2[i];
            }
            if(remain==1 && !three){
                check2 = false;
            }
        }

        check1 || check2 ? cout << "Yes\n": cout << "No\n";
    }

    return 0;}