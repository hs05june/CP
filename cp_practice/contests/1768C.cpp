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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n];
        mii cnt;
        rep(i,1,n)cnt[i] = 0;

        rp(i,0,n){
            cin >> a[i];
            cnt[a[i]]++;
        }

        bool ans = true;
        set<int> to_use,not_to_use;

        for(auto i : cnt){
            if(i.s>2){
                ans = false;
                break;
            }
            else if(i.s==0){
                not_to_use.insert(i.f);
            }
            else if(i.s==2){
                to_use.insert(i.f);
            }
        }

        if(!ans){
            cout << "NO\n";
            continue;
        }

        mii take;

        auto itr1 = to_use.begin(),itr2 = not_to_use.begin();
        while(itr1!=to_use.end() && itr2!=not_to_use.end()){
            if(*itr2>*itr1){
                ans = false;
                break;
            }
            take[*itr1] = *itr2;
            ++itr1;
            ++itr2;
        }

        if(!ans){
            cout << "NO\n";
            continue;
        }
        int b[2][n];
        rp(i,0,n){
            if(cnt[a[i]]==1){
                b[0][i] = b[1][i] = a[i];
            }
            else if(cnt[a[i]]==2){
                b[0][i] = a[i];
                b[1][i] = take[a[i]];
                cnt[a[i]] = 0;
            }
            else if(cnt[a[i]]==0){
                b[0][i] = take[a[i]];
                b[1][i] = a[i];
            }
        }

        cout << "YES\n";
        rp(i,0,2){
            rp(j,0,n){
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;}