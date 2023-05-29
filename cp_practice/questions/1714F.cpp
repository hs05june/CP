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

        int n,d[4][4];
        cin >> n >> d[1][2] >> d[2][3] >> d[3][1];  
        d[2][1] = d[1][2];
        d[3][2] = d[2][3] ;
        d[1][3] = d[3][1];

        vector<pair<int,pii>> has;
        has.pb({d[1][2],{1,2}});has.pb({d[2][3],{2,3}});has.pb({d[3][1],{3,1}});
        sort(all(has));
        reverse(all(has));

        if(has[0].f > (has[1].f + has[2].f)){
            cout << "NO\n";
            continue;
        }
        int left = has[0].s.f, right = has[0].s.s;
        int mid;
        rp(i,1,4){
            if(i!=left && i!=right){
                mid = i;
                break;
            }
        }
        if(has[0].f == (has[1].f + has[2].f)){
            if(n < has[0].f+1){
                cout << "NO\n";
                continue;
            }   
            int x = 4;
            // cout << left << " " << mid << " " << right << "\n";
            vector<pii>ans;
            int l = left, r = right, m = mid;
            rp(i,1,d[left][mid]){
                ans.pb({l,x});
                l = x;
                ++x;
            }
            ans.pb({l,mid});
            rp(i,1,d[mid][right]){
                ans.pb({m,x});
                m = x;
                ++x;
            }
            ans.pb({m,right});
            while(x<=n){
                ans.pb({1,x});
                ++x;
            }
            cout << "YES\n";
            for(auto i : ans)cout << i.f << " " << i.s << "\n";
            continue;
        }

        int a = (has[0].f+has[1].f-has[2].f);
        int b = has[1].f - (a/2);
        if((a%2) != 0 || n < (has[0].f + b + 1)){
            cout << "NO\n";
            continue;
        }
        vector<pii> ans;
        int x = 4;
        int l = left, r = right, m = mid;
        rp(i,1,has[0].f){
            ans.pb({l,x});
            l = x;
            ++x;
        }
        ans.pb({l,right});
        int pl = d[left][mid] - b;
        int y = 3 + pl;
        // cout << b << " " << a << " " << y << "\n";
        rp(i,1,b){
            ans.pb({y,x});
            y = x;
            ++x;
        }
        ans.pb({y,mid});
        while(x<=n){
                ans.pb({1,x});
                ++x;
            }
        cout << "YES\n";
        for(auto i : ans)cout << i.f << " " << i.s << "\n";
    }

    return 0;}