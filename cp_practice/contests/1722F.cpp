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

        int n,m;
        cin >> n >> m;

        string a[n];
        int visited[n][m] = {0};

        rp(i,0,n){
            rp(j,0,m){
                visited[i][j] = 0;
            }
        }

        bool ans = true;

        rp(i,0,n){
            cin >> a[i];
        }

        rp(i,0,n){
            rp(j,0,m){
                if(a[i][j]=='*' && visited[i][j]==0){
                    if((i+1)<n && (j+1)<m && a[i+1][j]=='*' && a[i+1][j+1]=='*'){
                        visited[i][j] = 1;
                        visited[i+1][j] = 1;
                        visited[i+1][j+1] = 1;
                        if(((i-1)>=0 && a[i-1][j]=='*') || ((i-1)>=0 && (j-1)>=0 && a[i-1][j-1]=='*') || ((j-1)>=0 && a[i][j-1]=='*') || ((j-1)>=0 && (i+1)<n && a[i+1][j-1]=='*') || ((i+2)<n && (j-1>=0) && a[i+2][j-1]=='*') || ((i+2)<n && a[i+2][j]=='*') || ((i+2)<n && (j+1)<m && a[i+2][j+1]=='*') || ((i+2)<n && (j+2)<m && a[i+2][j+2]=='*') || ((i+1)<n && (j+2)<m && a[i+1][j+2]=='*') || ((j+2)<m && a[i][j+2]=='*')||((i-1)>=0 && (j+1)<m && a[i-1][j+1]=='*') || ((j+1)<m && a[i][j+1]=='*')){
                            ans = false;
                            break;
                        }
                    }
                    else if((i+1)<n && (j-1)>=0 && a[i+1][j]=='*' && a[i+1][j-1]=='*'){
                        visited[i][j] = 1;
                        visited[i+1][j-1] = 1;
                        visited[i+1][j] = 1;
                        if(((i-1)>=0 && (j-1)>=0 && a[i-1][j-1]=='*') || ((j-2)>=0 && a[i][j-2]=='*') || ((j-2)>=0 && (i+1)<n && a[i+1][j-2]=='*') || ((i+2)<n && (j-2>=0) && a[i+2][j-2]=='*') || ((i+2)<n && (j-1)>=0 && a[i+2][j-1]=='*') || ((i+2)<n && a[i+2][j]=='*') || ((i+2)<n && (j+1)<m && a[i+2][j+1]=='*') || ((i+1)<n && (j+1)<m && a[i+1][j+1]=='*') || ((j+1)<m && a[i][j+1]=='*')||((i-1)>=0 && (j+1)<m && a[i-1][j+1]=='*')||((i-1)>=0 && a[i-1][j]=='*') || ((j-1)>=0 && a[i][j-1]=='*')){
                            ans = false;
                            // cout << "2\n";
                            break;
                        }

                    }
                    else if((i+1)<n && (j+1)<m && a[i+1][j]=='*' && a[i][j+1]=='*'){
                        visited[i][j] = 1;
                        visited[i+1][j] = 1;
                        visited[i][j+1] = 1;
                        if(((i-1)>=0 && a[i-1][j]=='*') || ((i-1)>=0 && (j-1)>=0 && a[i-1][j-1]=='*') || ((j-1)>=0 && a[i][j-1]=='*') || ((j-1)>=0 && (i+1)<n && a[i+1][j-1]=='*') || ((i+2)<n && (j-1>=0) && a[i+2][j-1]=='*') || ((i+2)<n && a[i+2][j]=='*') || ((i+2)<n && (j+1)<m && a[i+2][j+1]=='*') || ((i+1)<n && (j+2)<m && a[i+1][j+2]=='*') || ((j+2)<m && a[i][j+2]=='*')||((i-1)>=0 && (j+2)<m && a[i-1][j+2]=='*')||((i-1)>=0 && (j+1)<m && a[i-1][j+1]=='*') || ((i+1)<n && (j+1)<m && a[i+1][j+1]=='*')){
                            ans = false;
                            // cout << "3\n";
                            break;
                        }
                    }
                    else if((i+1)<n && (j+1)<m && a[i][j+1]=='*' && a[i+1][j+1]=='*'){
                        visited[i][j] = 1;
                        visited[i][j+1] = 1;
                        visited[i+1][j+1] = 1;
                        if(((i-1)>=0 && a[i-1][j]=='*') || ((i-1)>=0 && (j-1)>=0 && a[i-1][j-1]=='*') || ((j-1)>=0 && a[i][j-1]=='*') || ((j-1)>=0 && (i+1)<n && a[i+1][j-1]=='*') || ((i+2)<n && a[i+2][j]=='*') || ((i+2)<n && (j+1)<m && a[i+2][j+1]=='*') || ((i+2)<n && (j+2)<m && a[i+2][j+2]=='*') || ((i+1)<n && (j+2)<m && a[i+1][j+2]=='*') || ((j+2)<m && a[i][j+2]=='*')||((i-1)>=0 && (j+2)<m && a[i-1][j+2]=='*')||((i-1)>=0 && (j+1)<m && a[i-1][j+1]=='*') || ((i+1)<n && a[i+1][j]=='*')){
                            ans = false;
                            // cout << "4\n";
                            break;
                        }

                    }
                    else{
                        ans = false;
                        // cout << "last\n" << i << " " << j << "\n";
                        break;
                    }
                }
            }
            if(!ans){
                break;
            }
        }
        ans ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;}
