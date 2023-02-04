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

        int n,k;
        cin >> n >> k;
        int a[n],check[k];
        rp(i,0,n){
            cin >> a[i];
        }

        // rp(i,0,n){
        //     cin >> a[i];
        //     maxi = max(maxi,a[i]);
        //     mini = min(mini,a[i]);
        // }

        // int miniv[k],maxiv[k];

        // rp(i,0,k){
        //     miniv[i] = mini/(i+1);
        //     maxiv[i] = maxi/(i+1);
        // }

        // int y,z,x=LLONG_MAX;

        // rp(i,0,k){
        //     rp(j,0,k){
        //         if(abs(miniv[i]-maxiv[j])<=x){
        //             x = abs(miniv[i]-maxiv[j]);
        //             y = miniv[i];
        //             z = maxiv[j];
        //         }
        //     }
        // }

        // int maxi1 = max(y,z);
        // int mini1 = min(y,z);

        // rp(i,0,n){
        //     int h = LLONG_MAX;
        //     rep(j,1,k){
        //         int r1 = abs((a[i]/j)-maxi1);
        //         int r2 = abs((a[i]/j)-mini1);
        //         if(h>max(r1,r2)){
        //             h = max(r2,r1);
        //             p[i] = a[i]/j;
        //         }
        //     }
        //     maxi1 = max(maxi1,p[i]);
        //     mini1 = min(mini1,p[i]);
        // }

        // cout << (maxi1 - mini1) << "\n";
        rp(i,0,k){
            check[i] = a[n-1]/(i+1);
        }

        int b[n][k];
        ll ans = LLONG_MAX;
        rp(i,0,k){
            int maxi = check[i],mini = check[i];
            rp(j,0,n){
            int x;
            if(check[i]==0 || a[j]/check[i]>=k){
                x = a[j]/k;
            }
            else{
                ll z = a[j]/check[i];
                if((z+1)<=k){
                    if(a[j]/z>=mini && a[j]/z<=maxi){
                        x = a[j]/z;
                    }
                    else if(a[j]/(z+1)>=mini && a[j]/(z+1)<=maxi){
                        x = a[j]/(z+1);
                    }
                    else{
                        ll diff1 = min(abs(a[j]/z-maxi),abs(a[j]/z-mini));
                        ll diff2 = min(abs(a[j]/(z+1)-maxi),abs(a[j]/(z+1)-mini));
                        if(diff1<diff2){
                            x = a[j]/z;
                        }
                        else{
                            x = a[j]/(z+1);
                        }
                    }
                }
                else{
                    x = a[j]/z;
                }
            }
                    b[j][i] = x;
                    maxi = max(maxi,x);
                    mini = min(mini,x);
            }
        }
        rp(i,0,k){
            cout << i+1 << " => ";
            rp(j,0,n){
                cout << b[j][i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;}