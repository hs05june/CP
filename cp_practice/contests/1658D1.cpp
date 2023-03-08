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

        int l,r;
        cin >> l >> r;

        int arr[r-l+1];

        int maxi = 0;

        set<int> ele;

        rp(i,0,r-l+1){
            cin >> arr[i];
            maxi = max(maxi,arr[i]);
            ele.insert(arr[i]);
        }

        if(maxi==r){
            cout << "0\n";
            continue;
        }

        mii need,present;

        for(int i = l; i<=r; i++){
            int k = 0;
            while((1<<k)<=i){
                if(((1<<k)&i)!=0){
                    need[k]++;
                }
                ++k;
            }
        }

        for(int i =0; i <r-l+1; i++){
            int k = 0;
            while((1<<k)<=arr[i]){
                if(((1<<k)&arr[i])!=0){
                    present[k]++;
                }
                ++k;
            }
        }

        int ans = 0;

        for(int i = 0; i<=17;i++){
            int x = (1<<i);
            if(need[i]!=present[i]){
                ans|=x;
            }
        }

        cout << ans << "\n";
    }

    return 0;}