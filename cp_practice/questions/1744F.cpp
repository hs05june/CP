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

        int n;
        cin >> n;

        int arr[n], index[n+1];
        rp(i,0,n+1)index[i] = -1;

        rp(i,0,n){cin >> arr[i]; index[arr[i]] = i;}

        if(n==1){
            cout << "1\n";
            continue;
        }

        int ans = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        rp(i,1,n+1){
            mini = min(mini, index[i-1]);
            maxi = max(maxi, index[i-1]);
            int z = maxi - mini + 1;
            if(z > 2*i || (index[i]>=mini && index[i]<=maxi)){
                continue;
            }
            int low = 0, high = n-1;
            if(index[i] < mini) low = index[i]+1;
            if(index[i] > maxi) high = index[i]-1;
            int left = mini - low, right = high - maxi;
            int extra = min(2*i - z, left+right);
            int seedha = min(min(left,right),extra);
            int ulta = min(max(left,right),extra);
            ans += ((seedha+1)*(seedha+2))/2;
            ans += ((ulta-seedha)*(seedha+1));
            ans += ((extra-ulta)*(2*seedha-extra+ulta+1))/2;
        }

        cout << ans << '\n';

    }

    return 0;}