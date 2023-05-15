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

        int n,m;
        cin >> n >> m;

        cout << "? 1 1" << endl;
        int dist1,dist2,dist3;
        cin >> dist1;
        if(dist1==0){
            cout << "! 1 1" << endl;
            continue;
        }

        if(1+dist1>m){
            cout << "? " << 1+dist1 << " " << 1 << endl;
            cin >> dist2;
            cout << "! " << 1+dist1 << " " << 1 + dist2 << endl;
            continue;
        }

        if(1+dist1>n){
            cout << "? " << 1 << " " << 1+dist1 << endl;
            cin >> dist2;
            cout << "! " << 1+dist2 << " " << 1+dist1 << endl;
            continue;
        }

        cout << "? " << 1 << " " << 1+dist1 << endl;
        cin >> dist2;
        if(dist2 < dist1){
            cout << "! " << 1+dist2 << " " << 1+dist1 << endl;
            continue;
        }
        if(dist2==dist1){
            cout << "? " << 1+dist2 << " " << 1+dist1 << endl;
            cin >> dist3;
            cout << "! " << 1+dist2 << " " << 1+dist1-dist3 << endl;
        }
    }

    return 0;}