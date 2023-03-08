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

        mii cnt, ans;
        deq ele;

        rp(i,0,n){
            int x;
            cin >> x;
            cnt[x]++;
        }

        for(auto i : cnt)ele.pb(i.f);

        if(ele.size()==1){
            cout << cnt[ele[0]] << "\n";
            continue;
        }

        set<int> done[sz(ele)];

        rp(i,0,sz(ele)){
            rp(j,i+1,sz(ele)){
                if(sqrtl(ele[i])==ele[i] && sqrtl(ele[j])==ele[j]){
                    if(!(done[i].count(0))){
                        done[i].insert(0);
                        ans[0] += cnt[ele[i]];
                    }
                    if(!(done[j].count(0))){
                        done[j].insert(0);
                        ans[0] += cnt[ele[j]];
                    }
                    continue;
                }
                int x = ele[j] - ele[i];
                // cout << x << "\n";
                for(int k = 1; k*k<=x; k++){
                    if(x%k==0){
                        int a = k, b = x/k;
                        if((b+a)%2==0 && (b-a)%2==0 && (((b+a)/2)*((b+a)/2))>=ele[j] && (((b-a)/2)*((b-a)/2))>=ele[i]){
                            // cout << x << " " << k << " " << x/k << "\n";
                            int y = (((b+a)/2) * ((b+a)/2)) - ele[j];
                            if(!(done[i].count(y))){
                                done[i].insert(y);
                                ans[y] += cnt[ele[i]];
                            }
                            if(!(done[j].count(y))){
                                done[j].insert(y);
                                ans[y] += cnt[ele[j]];
                            }
                        }
                    }
                }
            }
        }

        int maxi = 0;
        for(auto i : cnt){
            maxi = max(maxi,i.s);
        }
        for(auto i : ans){
            // cout << i.f << " " << i.s << "\n";
            maxi = max(i.s,maxi);
        }
        cout << maxi << "\n";
    }

    return 0;}