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

        int arr[n];

        int maxi = 0,index = 0;

        rp(i,0,n){
            cin >> arr[i];
            if(maxi<=arr[i]){
                maxi = arr[i];
                index = i;
            }
        }


        rp(i,0,n){
            if(arr[i]==maxi && ((i>=2 && (n-1-i)>=2) ||  i==0 || i==n-1)){
                index = i;
                break;
            }
        }

        if(n==2){
            int ans = max(arr[0]+arr[1],2*abs(arr[0]-arr[1]));
            cout << ans << "\n";
            continue;
        }

        if(n==3 && (arr[0]==maxi || arr[2]==maxi)){
            cout << 3*maxi << "\n";
            continue;
        }

        if(n==3){
            int ans = arr[0]+arr[1]+arr[2];
            int x1 = abs(arr[0]-arr[1]);
            int x2 = abs(arr[2]-arr[1]);
            ans = max(ans,3*x1);
            ans = max(ans,3*x2);
            ans = max(ans,3*arr[0]);
            ans = max(ans,3*arr[2]);
            cout << ans << "\n";
            continue;
        }
        
        if(n>=4){
            cout << n*maxi<< "\n";
            continue;
        }
    }

    return 0;}