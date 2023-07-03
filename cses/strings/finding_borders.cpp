#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

    string a;
    cin >> a;

    int n = a.size();

    int pi[n];
    pi[0] = 0;

    int j = 0, i = 1;

    while(i < n){
        if(a[j]==a[i]){
            ++j;
            pi[i] = j;
            ++i;
        }
        else{
            if(j==0){
                pi[i] = 0;
                ++i;
            }
            else{
                j = pi[j-1];
            }
        }
    }

    multiset<int> ans;

    int x = pi[n-1];
    while(x!=0){
        ans.insert(x);
        x = pi[x-1];
    }

    for(auto i : ans)cout << i << " ";

    return 0;}