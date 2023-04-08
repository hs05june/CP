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

        string a;
        cin >> a;

        // if(t==277-112){
        //     cout << a << "\n";
        // }

        // string b = a;

        // reverse(all(b));

        // if(a==b){
        //     cout << "Draw\n";
        //     continue;
        // }

        // bool check = true;

        // for(int i = 0; i < sz(a);i+=2){
        //     if(a[i]!=a[i+1])check = false;
        // }

        // if(check){
        //     cout << "Draw\n";
        //     continue;
        // }

        // cout << "Alice\n";

        bool check = true;
        int l = 0, r = sz(a)-1;

        while (l<r)
        {   
            if((a[l]!=a[l+1] && a[l]!=a[r]) || (a[r]!=a[r-1] && a[r]!=a[l])){
                check = false;
                // cout << l << " " << r << " a\n";
                break;
            }

                int cntl = 0,cntr = 0;
                rp(i,l,r+1){
                    if(a[l]==a[i])cntl++;
                    else break;
                }
                rep(i,r,l){
                    if(a[r]==a[i])cntr++;
                    else break;
                }

                if(a[l]==a[r] && (cntl%2)!=(cntr%2)){
                    check = false;
                    // cout << l << " " << r << " b\n";
                    break;
                }

                if(a[l]!=a[r] && ((cntl%2)!=0 || (cntr%2)!=0)){
                    check = false;
                    // cout << l << " " << r << " c\n";
                    break;
                }

                if(a[l]==a[r]){
                    ++l;
                    --r;
                }
                else if(a[l]==a[l+1]){
                    l+=2;
                }
                else if(a[r]==a[r-1]){
                    r-=2;
                }
        }

        check ? cout << "Draw\n" : cout << "Alice\n";    

    }

    return 0;}  