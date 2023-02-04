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

        // int n;
        // cin >> n;

        // int arr[n];
        // map<int,int> cnt;

        // rp(i,0,n){cin >> arr[i];cnt[(arr[i]%2)]++;}

        // ll to_collect = n%2 == 0 ? n/2 : n/2+1;

        // if((to_collect & 1) && (cnt[0]==0)){
        //     cout << "Bob\n";
        //     continue;
        // }

        // if(to_collect%2==1){
        //     cnt[0]--;
        //     to_collect--;
        // }
        // bool ans = false;

        // for(auto i : cnt){
        //     cout << i.first<<" "<<i.second<<"\n";
        // }

        // for(int i = to_collect; i>=0; i-=2){
        //     ll even = i, odd = to_collect - i;
        //     if((cnt[0]>=2*even && cnt[1]>=(2*odd-1)) || (cnt[0]>=(2*even-1) && cnt[1]>=(2*odd))){
        //         ans = true;
        //         break;
        //     }
        // }
        // ans ? cout << "Alice\n" : cout << "Bob\n";

        int n;
        cin >> n;

        ll even = 0, odd = 0;

        rp(i,0,n){
            ll x;
            cin >> x;
            if(x & 1)odd++;
            else even++;
        }
        if(odd%4==2)cout << "Bob\n";
        else if(odd%4==3)cout << "Alice\n";
        else if(odd%4==0)cout << "Alice\n";
        else if(even%2==1)cout << "Alice\n";
        else cout << "Bob\n";
    }

    return 0;}