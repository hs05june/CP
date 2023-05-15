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

        int n;
        cin >> n;

        int arr[n];
        multiset<int> pos,neg;
        rp(i,0,n){cin >> arr[i];
        if(arr[i]>0)pos.insert(arr[i]);
        if(arr[i]<0)neg.insert(-arr[i]);}

        if(sz(pos)==0 && sz(neg)==0){
            cout << "No\n";
            continue;
        }

        deq ans;
        rp(i,0,n-sz(pos)-sz(neg))ans.pb(0);

        int sum = 0;

        while(sz(pos)>0 && sz(neg)>0){
            int x = *(--pos.end());
            int y = *(--neg.end());
            if(sum+x>y){
                ans.pb(-y);
                sum-=y;
                neg.erase(--neg.end());
            }
            else{
                ans.pb(x);
                sum+=x;
                pos.erase(--pos.end());
            }
        }

        for(auto i : pos)ans.pb(i);
        for(auto i : neg)ans.pb(-i);
        cout << "Yes\n";
        for(auto i : ans)cout << i << " ";
        cout << "\n";
    }

    return 0;}