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

        deq arr;

        rp(i,0,n){
            int a;
            cin >> a;
            arr.pb(a);
        }

        sort(all(arr));


        if(arr[0]==arr[n-1]){
            cout << n/2 << "\n";
            continue;
        }

        set<int> hid;
        mii cnt;
        for(auto i : arr){
            cnt[i]++;
            hid.insert(i);
        }
        
        deq uniq;
        for(auto i : hid){
            uniq.pb(i);
        }

        int start = 0,end = 0,x = 1;

        int i = 0, j = sz(uniq)-1;

        while(i<=j){
            if(start<=end){
                start+=cnt[uniq[i]];
                ++i;
            }
            else{
                end+=cnt[uniq[j]];
                --j;
            }
        }

        cout << start * end << "\n";
    }

    return 0;}  