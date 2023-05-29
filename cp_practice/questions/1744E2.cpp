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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int a,b,c,d;
        cin >> a >> b >> c >> d;

        vector<pii> divisor1,divisor2;

        for(int i = 1; i * i <= a; i++){
            if(a%i==0){
                divisor1.pb({i,a/i});
            }
        }

        for(int i = 1; i * i <= b; i++){
            if(b%i==0){
                divisor2.pb({i,b/i});
            }
        }

        pii ans = {0,0};
        for(auto i : divisor1){
            for(auto j : divisor2){
                deq possible;
                possible.pb(i.f*j.f);
                possible.pb(i.f*j.s);
                possible.pb(i.s*j.f);
                possible.pb(i.s*j.s);
                for(auto k : possible){
                    int x = k, y = ((a*b)/k);
                    int x1 = (c/x)*x, y1 = (d/y)*y;
                    if(x1>a && x1<=c && y1>b && y1<=d){
                        ans = {x1,y1};
                        break;
                    }
                    int x2 = (d/x)*x, y2 = (c/y)*y;
                    if(y2>a && y2<=c && x2>b && x2<=d){
                        ans = {y2,x2};
                        break;
                    }
                }
                if(ans.f!=0 && ans.s!=0)break;
            }
            if(ans.f!=0 && ans.s!=0)break;
        }

        if(ans.f==0 && ans.s==0){
            cout <<"-1 -1\n";
        }
        else{
            cout << ans.f << " " << ans.s << "\n";
        }

    }

    return 0;}