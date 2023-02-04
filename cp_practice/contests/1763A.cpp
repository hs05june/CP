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

        set<int> set_bits,unset_bits;

        int arr[n];
        rp(i,0,n){
            cin >> arr[i];
            int j = 0;
            while(j<=10){
                if(((1<<j)&arr[i])==0){
                    unset_bits.insert(j);
                }
                else{
                    set_bits.insert(j);
                }
                ++j;
            }
        }

        int maxi = 0, mini = 0;

        for(auto i : set_bits){
            maxi = (maxi | (1<<i));
        }

        int max_bit = *(--set_bits.end());

        int to_use[11] = {0};

        for(auto i : unset_bits){
            to_use[i] = 1;
        }

        for(int i = 0; i<=10;i++){
            if(to_use[i]==0){
                mini = (mini | (1<<i));
            }
        }

        cout << maxi - mini << "\n";

    }

    return 0;}  