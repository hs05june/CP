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

        string a[n];
        rp(i,0,n)cin >> a[i];
        set<string> present2,present3;
        bool ans = false;

        rp(i,0,n){
            if(a[i].length()==1){
                ans = true;
                break;
            }
            else if(a[i].length()==2){
                if(a[i][0]==a[i][1]){
                    ans = true;
                    break;
                }
                string z = "";
                z.pb(a[i][1]);z.pb(a[i][0]);
                if(present2.count(z) || present3.count(z)){
                    ans = true;
                    break;
                }
                present2.insert(a[i]);
            }
            else if(a[i].length()==3){
                if(a[i][0]==a[i][2]){
                    ans = true;
                    break;
                }
                string z1 = "";
                z1.pb(a[i][2]);z1.pb(a[i][1]);z1.pb(a[i][0]);
                string z3 = "";
                z3.pb(a[i][2]);z3.pb(a[i][1]);

                if(present3.count(z1) || present2.count(z3)){
                    ans = true;
                    break;
                }
                present3.insert(a[i]);
                z1 = "";
                z1.pb(a[i][0]);z1.pb(a[i][1]);
                present3.insert(z1);
            }
        }

        ans ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;}