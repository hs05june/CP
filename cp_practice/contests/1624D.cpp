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
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;

        string a;
        cin >> a;

        map<char,int> cnt;

        ll two = 0,one = 0;

        rp(i,0,a.length()){
            cnt[a[i]]++;
        }

        for(auto i : cnt){
            if((i.s) & 1){
                one++;
            }
            two+=((i.s)/2);
        }

        ll mini = 0;

        ll z = two%k;
        mini += (((ll)(two/k))*2);
        one+=z*2;
        if(one>=k){
            mini++;
           }

        if(mini==0)mini=1;
        cout << mini << "\n" ;
    }

    return 0;}