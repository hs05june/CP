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

        string rec;
        cin >> rec;
        map<char,int> cnt;

        for(auto i : rec){
            cnt[i]++;
        }

        string a = "", b = "";

        // cout << sz(cnt) << "\n";

        if(sz(cnt)==1){
            cout << rec << "\n";
            continue;
        }

        if(sz(cnt)==2){
            vector<char> letters;
            for(auto i : cnt){
                if(i.s%2==1){
                    letters.pb(i.f);
                }
                rp(j,0,(i.s/2)){
                    a.pb(i.f);
                    b.pb(i.f);
                }
            }
            if(sz(letters)==1)a.pb(letters[0]);
            else if(sz(letters)==2){a.pb(letters[0]);b.pb(letters[1]);}
            string ans = a;
            for(int i = sz(b)-1;i>=0;i--){
                ans.pb(b[i]);
                a.pb(b[i]);
            }
            reverse(all(ans));
            cout << max(ans,a) << "\n";
            continue;
        }

        char single = '1';
        vector<char> letters;
        for(auto i : cnt)letters.pb(i.f);
        int i = 0;
        for(;i<sz(letters);i++){
            if(single == '1'){
                int x = cnt[letters[i]];
                if(x%2==1){
                    single = letters[i];
                }
                rp(j,0,(x/2)){
                    a.pb(letters[i]);
                    b.pb(letters[i]);
                }
            }
            else{
                if(i==(sz(letters)-1)){
                    // cnt[letters[i]]-=2;
                    // a.pb(letters[i]);
                    // b.pb(letters[i]);
                    rp(j,0,(cnt[letters[i]]/2)){
                        a.pb(letters[i]);
                        b.pb(letters[i]);
                    }
                    cnt[letters[i]] = cnt[letters[i]]%2;
                    b.pb(single);
                    single = '1';
                }
                else{ 
                cnt[letters[i]]--;
                a.pb(letters[i]);
                b.pb(single);
                single = '1';}
                break;
            }
        }
        if(single!='1'){
            a.pb(single);
            single = '1';
        }
        for(;i<sz(letters);i++){
            rp(j,0,cnt[letters[i]]){
                a.pb(letters[i]);
            }
        }

        string ans = a;
        rep(i,sz(b)-1,0){
            a.pb(b[i]);
            ans.pb(b[i]);
        }
        reverse(all(ans));
        cout << max(a,ans) << "\n";
    }

    return 0;}