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

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;
        int high = n,low = 1,mid = (n+1)/2;
        while((high-low)>0){
            mid= (low+high)/2;
            int cnt = 0;
            int arr;
            cout << "? " << low << " " << mid << endl;
            for(int i = 0; i <= (mid-low) ; i++){
                cin >> arr;
                if(arr<=mid && arr>=low){
                    cnt++;
                }
            }
            if((cnt % 2) == 1){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        cout << "! " << high << endl;
    }

    return 0;}