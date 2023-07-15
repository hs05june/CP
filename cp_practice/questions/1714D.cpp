#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

        string a;
        cin >> a;

        int m = sz(a);

        int n;
        cin >> n;

        string b[n];
        rp(i,0,n)cin >> b[i];

        int l = 0, r = 0;

        vector<pii> ans;
        bool ans1 = true;

        while(r < m){
            int x = r-1, y = -1,z = -1;
            rp(i,l,r+1){
                rp(j,0,n){
                    bool check = true;
                    rp(h,0,sz(b[j])){
                        if(i + h >= m){
                            check = false;
                            break;
                        }
                        if(b[j][h] != a[i+h]){check = false;break;}
                    }
                    if(check){
                        if(i + sz(b[j]) - 1 > x){
                            x = i + sz(b[j]) - 1;
                            y = j;
                            z = i+1;
                        }
                    }
                }
            }
            if(y==-1){
                ans1 = false;
                break;
            }
            ans.pb({y+1,z});
            l = r+1;
            r = x+1;
        }

        if(!ans1){
            cout << "-1\n";
            continue;
        }

        cout << sz(ans) << "\n";
        for(auto i : ans){
            cout << i.f << " " << i.s << "\n";
        }

    }

    return 0;}