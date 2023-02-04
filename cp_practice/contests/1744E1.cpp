//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int a,b,c,d;
        cin >> a >> b >> c >> d;

        ll n = a*b;

        deque<pii> factors;

        for(int i = 1; i*i<=n; i++){
            if(n%i==0){
                factors.push_back({i,n/i});
            }
        }

        bool ans = false;

        // rp(i,0,sz(factors)){
        //     cout << factors[i].f << " " << factors[i].s << "\n";
        // }

        // for(auto i : factors){
        //     if((i.f<=c && i.f>a && i.s <=d && i.s>b)||(i.f<=d && i.f>b && i.s <=c && i.s>a)){
        //         ans = true;
        //         cout << i.f << " " << i.s << "\n";
        //         break;
        //     }
        // }

        for(auto i : factors){
            ll x = c%(i.f);
            ll y = d%(i.s);
            if(c-x>a && d-y>b){
                cout << c - x << " " << d - y << "\n";
                ans = true;
                break;
            }
            x = c%(i.s);
            y = d%(i.f);
            if(c-x>a && d-y>b){
                cout << c - x << " " << d - y << "\n";
                ans = true;
                break;
            }
        }

        if(!ans){
            cout << "-1 -1\n";
        }
    }

    return 0;}