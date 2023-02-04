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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        string a;
        cin >> a;

        int arr[n+1] = {0};

        rep(i,1,n)cin >> arr[i];

        int visited[n+1] = {0};
        vector<deq> graphs;

        rep(i,1,n){
            if(visited[i]==0){
                visited[i] = 1;
                deq h;
                int x = i;
                h.pb(x);
                int y = arr[x];
                while(y!=x){
                    visited[y] = 1;
                    h.pb(y);
                    y = arr[y];
                }
                graphs.pb(h);
            }
        }

        // rp(i,0,sz(graphs)){
        //     for(auto j : graphs[i]){
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }

        int ans = 1;
        int steps[sz(graphs)] = {0};
        rp(i,0,sz(graphs)){
            deque<char> letter,check;
            rp(j,0,sz(graphs[i])){
                letter.pb(a[graphs[i][j]-1]);
                check.pb(a[graphs[i][j]-1]);
            }
            rep(j,1,sz(graphs[i])){
                char x = check[0];
                check.pop_front();
                check.pb(x);
                if(letter==check){
                    steps[i] = j;
                    break;
                }
            }
        }

        // rp(i,0,sz(graphs))cout << steps[i] << " ";
        // cout << endl;
        rp(i,0,sz(graphs)){
            ans = (ans*steps[i])/(__gcd(ans,steps[i]));
        }
        cout << ans << endl;
    }

    return 0;}