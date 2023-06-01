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

deq graph[1007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        deq dfs;
        int visited[n+1];
        rp(i,0,n+1){
            graph[i].clear();
            visited[i] = 0;
        }

        int parr;
        cout << "+ " << n << endl;
        cin >> parr;
        cout << "+ " << n+1 << endl;
        cin >> parr;

        rp(i,1,n+1){
            int x = n - i;
            if(x>0 && x<=n){
                if(i != x){
                    graph[i].pb(x);
                }
            }
        }

        rp(i,1,n+1){
            int x = n + 1 - i;
            if(x>0 && x<=n){
                if(i != x){
                    graph[i].pb(x);
                }
            }
        }
        stack<int> st;
        rp(i,1,n+1){
            if(visited[i]==0 && graph[i].size()==1){
                visited[i] = 1;
                st.push(i);
                dfs.pb(i);
                while(!st.empty()){
                    int x = st.top();
                    st.pop();
                    for(auto j : graph[x]){
                        if(visited[j]==0){
                            visited[j] = 1;
                            st.push(j);
                            dfs.pb(j);
                        }
                    }
                }
            }
        }

        int maxi = 0, y = 1;

        rp(i,2,n+1){
            cout << "? 1 " << i << endl;
            int x;
            cin >> x;
            if(x>maxi){
                maxi = x;
                y = i;
            }
        }

        mii ans;
        ans[0] = y;
        rp(i,1,n+1){
            if(i==y)continue;
            cout << "? " << y << " " << i << endl;
            int x;cin >> x;
            ans[x] = i;
        }

        int ans1[n+1],ans2[n+1];

        for(int i = 0; i < n; i++){
            int x = ans[i];
            ans1[dfs[i]] = x;
            ans2[dfs[n-i-1]] = x;
        }

        cout << "! ";
        rp(i,1,n+1)cout << ans1[i] << " ";
        rp(i,1,n+1)cout << ans2[i] << " ";
        cout << endl;
        cin >> parr;
    }

    return 0;}