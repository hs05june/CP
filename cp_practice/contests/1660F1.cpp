#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
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

        string a;
        cin >> a;

        int plus[n+1],minus[n+1];

        rep(i,0,n){
            plus[i] = 0;
            minus[i] = 0;
        }

        rep(i,1,n){
            plus[i] = plus[i-1] + (a[i-1]=='+');
            minus[i] = minus[i-1] + (a[i-1]=='-');
        }

        vector<pii> doub;

        rp(i,0,n){
            if(a[i]=='-'){
                int x = i;

                while(i<n && a[i]=='-'){
                    ++i;
                }
                doub.pb({x+1,i});
                --i;
            }
        }

        mii doub_cnts,doub_cnte;

        for(auto i : doub){
            rep(j,i.f,i.s){
                doub_cnte[j] = i.s;
                doub_cnts[j] = i.f;
            }
        }

        int double_minus[n+1] = {0};

        rep(i,0,n){
            double_minus[i] = 0;
        }

        rep(i,1,n){
            if(a[i-1]=='-' && a[i]=='-'){
                double_minus[i] = 1 + double_minus[i-1];
                double_minus[i+1] = double_minus[i];
                ++i;
                continue;
            }
            double_minus[i] = double_minus[i-1];
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                int p = plus[j] - plus[i-1], m = minus[j] - minus[i-1];
                if(p>m){
                    continue;
                }
                if(p==m){
                    ans++;
                    continue;
                }
                int x = i,y=j;
                int maxi_doub = 0;
                if(a[i-1]=='-'){
                    int end = doub_cnte[i];
                    if(end>=j){
                        if((j-i+1)%3==0)ans++;
                        continue;
                    }
                    maxi_doub+=(end-i+1);
                    x = end+1;
                }
                if(a[j-1]=='-'){
                    int start = doub_cnts[j];
                    maxi_doub+=(j-start+1);
                    y = start - 1;
                }
                maxi_doub+=(double_minus[y]-double_minus[x-1]);
                if((m-p)%3==0 && maxi_doub>=((m-p)/3))ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;}