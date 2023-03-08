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

        int n;
        cin >> n;

        int k[n+1],h[n+1];
        k[0] = 0; h[0] = 0;

        rp(i,1,n+1)cin >> k[i];
        rp(i,1,n+1)cin >> h[i];

        vector<pii> attacks;

        rp(i,1,n+1){
            int x = k[i] - h[i] + 1;
            attacks.pb({x,k[i]});
        }

        sort(all(attacks));
        vector<pii> final_attack;

        for(auto i : attacks){
            if(final_attack.empty()){
                final_attack.pb(i);
            }
            else{
                auto z = final_attack.back();
                if(z.s>=i.f){
                    final_attack.pop_back();
                    final_attack.pb({min(z.f,i.f),max(z.s,i.s)});
                }
                else{
                    final_attack.pb(i);
                }
            }
        }

        int ans = 0;
        for(auto i : final_attack){
            int z = i.s - i.f + 1;
            ans+=(z*(z+1))/2;
        }

        cout << ans << "\n";

    }

    return 0;}