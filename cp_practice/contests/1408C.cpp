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

    int t = 1;
    cin >> t;

    while(t--){

        int n,l;
        cin >> n >> l;

        double a[n+2];

        a[0] = 0;
        a[n+1] = l;

        rep(i,1,n){
            cin >> a[i];
        }

        vector<double> arr1,arr2;
        double x = 1,y=0,sum = 0;

        arr1.pb(0);

        rep(i,1,n+1){
            arr1.pb((a[i]-y)/x+sum);
            sum+=(a[i]-y)/x;
            ++x;
            y = a[i];
        }

        x = 1;y=l;sum=0;

        arr2.pb(0);
        for(int i = n; i >= 0; i--){
            arr2.pb((y-a[i])/x+sum);
            sum+=(y-a[i])/x;
            ++x;
            y = a[i];
        }

        reverse(all(arr2));

        int ind;

        for(int i = 0; i <= (n+1); i++){
            if(arr1[i]>=arr2[i]){
                ind = i;
                break;
            }
        }

        double speed1 = ind, speed2 = n-ind+2, dis = a[ind] - a[ind-1],t1 = arr1[ind-1],t2 = arr2[ind];

        double ans = (dis+(speed1*t1)+(speed2*t2))/(speed1+speed2);
        cout << ans << "\n";
    }

    return 0;}