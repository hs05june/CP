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
    // cin >> t;

    while(t--){

        int n;
        cin >> n;

        string a[n];

        map<string,deq> ma;

        set<char> x[n];
        string b[n];

        rp(i,0,n){
            cin >> a[i];
        }

        int ans = 0;

        rp(i,0,n){
            int cnt[26] = {0};
            string y = "";
            string h = "";

            for(char j = 'a'; j<='z';j++){
                x[i].insert(j);
                cnt[(int)(j-'a')] = 0;
            }

            for(auto j : a[i]){
                if(cnt[(int)(j-'a')]==0){
                    x[i].erase(j);
                }
                cnt[(int)(j-'a')]++;
            }

            rp(j,0,26){
                if(cnt[j]%2==0){
                    y.pb('1');
                    // if(cnt[j]==0)h.pb('1');
                    // else h.pb('0');
                    h.pb('0');
                }
                else{
                    y.pb('0');
                    h.pb('1');
                }
            }
            b[i] = h;
            ma[y].pb(i);
            for(auto j : ma[h]){
                if((a[i].length() + a[j].length())%2==0)continue;
                int l = 0;
                for(char k = 'a'; k <= 'z'; k++){
                    if((x[i].count(k)) && (x[j].count(k))){
                        // ans++;
                        // break;
                        ++l;
                    }
                }
                if(l==1){
                    ans++;
                    cout << i << " " << j << "\n";
                }
            }
        }

        cout << ans << "\n";

        // for(auto i : ma){
        //     cout << i.f << " => ";
        //     for(auto j : i.s)cout << j << " ";
        //     cout << "\n";
        // }

        // rp(i,0,n){
        //     cout << i << " " << b[i] << "\n";
        // }

    }

    return 0;}