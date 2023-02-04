#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define int long long
using namespace std;

int moves[1007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);
    
    rep(i,2,1000){
        moves[i] = INT_MAX;
        for(int j = 1; j <= (i-1); j++){
            int x = (i - j);
            int y = x/j;
            if(y<=0)break;
            if(x/y==j){
                moves[i] = min(moves[i],moves[i-j]+1);
            }
            else if((y-1)>0 && x/(y-1)==j){
                moves[i] = min(moves[i],moves[i-j]+1);
            }
        }
    }

    int t = 1;
    cin >> t;

    while(t--){
        
        int n,k;
        cin >> n >> k;
        int b[n+1],c[n+1];
        int sum = 0;
        b[0] = 0;
        c[0] = 0;

        rep(i,1,n){
            cin >> b[i];
        }
        
        rep(i,1,n){
            cin >> c[i];
            sum+=c[i];
        }

        if(k>=12*n){
            cout << sum << "\n";
            continue;
        }

        int dp[n+1][k+1];
        rep(i,0,k){
            dp[0][i] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <=k; j++){
                dp[i][j] = dp[i-1][j];
                if((j-moves[b[i]])>=0)dp[i][j]= max(dp[i][j],dp[i-1][j-moves[b[i]]]+c[i]);
            }
        }

        cout << dp[n][k] << "\n";
    }    

    return 0;}