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
const ll M = 998244353;
using namespace std;

int factorials[200007];

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

    factorials[0] = 1;

    rep(i,1,200000){
        factorials[i] = (i%M * factorials[i-1]%M)%M;
    }

    while(t--){

        int n;
        cin >> n;

        int arr[n];
        mii cnt;

        rp(i,0,n){
            cin >> arr[i];
            cnt[arr[i]]++;
            }

        sort(arr,arr+n);

        if(arr[0]==arr[n-1]){
            cout << factorials[n]%M << "\n";
            continue;
        }


        int maxi = arr[n-1],second_maxi = arr[0];

        for(int i = n-1; i >= 0; i--){
            if(arr[i]!=maxi){
                second_maxi = arr[i];
                break;
            }
        }

        if(cnt[maxi]>1){
            cout << factorials[n]%M <<"\n";
            continue;
        }

        if(maxi-second_maxi>1){
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;
        int NOT = n - (cnt[maxi] + cnt[second_maxi]);
        int k = n-1;

        rep(i,0,NOT){
            ans = (ans%M + (factorials[k-i]%M * modInverse(factorials[NOT-i],M)%M)%M)%M;
        }
        ans = (ans%M * factorials[NOT]%M)%M;
        ans = (ans%M * cnt[second_maxi]%M)%M;
        cout << ans%M << "\n";
    }

    return 0;}