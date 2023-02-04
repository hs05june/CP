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

vector<char> all_chars;
vector<set<char>> subsets;

void make_subsets(int index, int n, int k,set<char> due){
    if(k==0){
        subsets.pb(due);
        return;
    }
    if(n-index==k){
        for(int i = index; i < sz(all_chars); i++){
            due.insert(all_chars[i]);
        }
        subsets.pb(due);
        return;
    }
    due.insert(all_chars[index]);
    make_subsets(index+1,n,k-1,due);
    due.erase(all_chars[index]);
    make_subsets(index+1,n,k,due);
}

int solve(set<char>due, string a, string b){
    int ans = 0;
    vector<int> possible;

    for(int i = 0; i < a.length(); i++){
        if(a[i]==b[i] || due.count(a[i])){
            int x = 0;
            while(i<a.length() && (a[i]==b[i] || due.count(a[i]))){
                ++i;
                ++x;
            }
            --i;
            possible.push_back(x);
        }
    }

    for(auto i : possible){
        ans+=((i*(i+1))/2);
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

        all_chars.clear();
        subsets.clear();

        int n,k;
        cin >> n >> k;

        string a,b;

        cin >> a >> b;
        set<char> diff;

        for(auto i : a){
            diff.insert(i);
        }

        if(k>=diff.size()){
            cout << (n*(n+1))/2 << "\n";
            continue;
        }

        for(auto i : diff){
            all_chars.pb(i);
        }
        set<char> due;
        subsets.pb(due);
        make_subsets(0,sz(all_chars),k,due);

        int ans = 0;

        for(auto i : subsets){
            ans = max(ans,solve(i,a,b));
        }
        cout << ans << "\n";
    }

    return 0;}