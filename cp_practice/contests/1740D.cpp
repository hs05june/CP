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

int k;
int fenwick[500007];

void update(int n){
    for(int i = n; i<=2*k; i+=(i&(-i))){
        fenwick[i]+=1;
    }
}
int sum(int n){
    int ans = 0;
    for(int i = n; i>0; i-=(i&(-i))){
        ans+=fenwick[i];
        // cout << i << "\n";
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m >> k;
        int z = max(n,m);
        int a[k+1] = {0};
        rep(i,0,2*k)fenwick[i] = 0;
        rep(i,1,k)cin >> a[i];

        mii cnt;

        // set<int> fen;-

        // rp(i,1,n){
        //     fen.insert(a[i]);            
        //     auto itr = fen.find(a[i]);
        //     int x = itr  - fen.begin();
        //     cnt[a[i]] = x;
        // }

        // for(auto i : cnt){
        //     cout << i.f << " " << i.s << "\n";
        // }

        rep(i,1,k){
            update(a[i]);
            cnt[a[i]] = sum(a[i]-1);
        }
        bool check = true;
        for(auto i : cnt){
            // cout << i.f << " " << i.s << "\n";
            if(i.s>n*m-4){
                check = false;
            }
        }

        check ? cout << "YA\n" : cout << "TIDAK\n";

    }

    return 0;}