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

        string a,b;

        cin >> a >> b;

        if(b.length()>a.length()){
            cout << "NO\n";
            continue;
        }

        if(b.length()==a.length()){
            if(a==b){
                cout << "YES\n";
            }
            else{
                cout <<"NO\n";
            }
            continue;
        }

        bool ans = false;

        // int start[2] = {-1,-1};

        deq start;

        for(int i = 0; i < a.length(); i++){
            if(a[i]==b[0]){
                // start[i%2] = i;
                start.pb(i);
            }
        }

        rp(i,0,start.size()){
            // if(start[i]==-1)continue;
            int j = 1;
            int x = start[i];
            rp(k,start[i]+1,a.length()){
                if(j>=b.length()){
                    ans = true;
                    break;
                }
                if(a[k]==b[j] && (k-x)%2==1){
                    ++j;
                    x = k;
                    if(j>=b.length()){
                        ans = true;
                        break;
                    }
                }
            }
        }

        ans ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;}