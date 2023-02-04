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

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        int root = 0;
        int parent[n+1] = {0};

        rep(i,1,n){
            int x;
            cin >> x;
            if(i==x){
                root = x;
            }
            else{
                parent[i] = x;
            }
        }

        int perm[n+1]={0};
        int b[n+1] = {0};
        int x;
        cin >> x;
        b[1] = x;
        bool possible = true;
        perm[x] = 1;
        if(x!=root){
            possible = false;
        }
        rep(i,2,n){
            cin >> x;
            b[i] = x;
            if(perm[parent[x]]==0){
                possible = false;
            }
            perm[x] = 1;
        }

        if(!possible){
            cout << "-1\n";
            continue;
        }

        map<int,int> dist;

        x = 0;
        rep(i,1,n){
            dist[b[i]] = x;
            ++x;
        }

        rep(i,1,n){
            if(i==root){
                cout << "0 ";
                continue;
            }
            cout <<  dist[i] - dist[parent[i]]<<" ";
        }
        cout << "\n";
    }

    return 0;}