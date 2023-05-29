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


int preffix[400050];
int fact[400050];
mii hashing;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    fact[0] = fact[1] = 1;

    rp(i,2,400007)fact[i] = (fact[i-1]%M * i%M)%M;

    while(t--){

        int n,m;
        cin >> n >> m;
        hashing.clear();
        rp(i,0,2*n+1)preffix[i] = 0;
        set<int> uniq, element;
        int arr[n];
        mii cnt;
        rp(i,0,n){
            cin >> arr[i];
            cnt[arr[i]]++;
            uniq.insert(arr[i]);
            uniq.insert(arr[i]+m-1);
            element.insert(arr[i]);
        }

        int x = 1;
        for(auto i : uniq){
            hashing[i] = x;
            ++x;
        }

        for(auto i : element){
            preffix[hashing[i]] = 1;
        }

        rp(i,1,x+1){
            preffix[i]+=preffix[i-1];
        }

        if(m==1){
            cout << n << "\n";
            continue;
        }

        x = 0;

        mii current;
        int itr = *(uniq.begin());
        set<int> to_check;
        for(auto i : uniq){
            if(i>=itr+m)break;
            if(cnt[i]==0)continue;
            current[cnt[i]]++;
            to_check.insert(cnt[i]);
        }

        itr+=(m-1);

        int ans = 0;
        for(auto i : element){
            auto itr1 = uniq.lower_bound(itr);
            ++itr1;
            while(*itr1<i+m){
                itr = *itr1;
                if(cnt[*itr1]!=0){current[cnt[*itr1]]++;to_check.insert(cnt[*itr1]);}
                itr1++;
            }
            int x = hashing[i];
            int z = hashing[i+m-1];
            int left = preffix[z] - preffix[x];
            int y = 0;
            if(left>=(m-1)){
                y = 1;
                for(auto j : to_check){
                    y = (y%M * power(j,current[j],M)%M)%M;
                }
            }
            ans = (ans%M + y%M)%M;
            current[cnt[i]]--;
            if(current[cnt[i]]==0)to_check.erase(cnt[i]);
        }

        cout << ans << "\n";
    }

    return 0;}