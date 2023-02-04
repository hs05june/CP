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
const ll M = 9000000000000000007;
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,x;
        cin >> n >> x;


        int y = 0;
        int mini = LLONG_MAX,maxi = 0;

        if(n==x){
            cout << n << "\n";
            continue;
        }

        if(x==0){
            while(n>=((1LL)<<y)){
                ++y;
            }
            cout << ((1LL)<<y) << "\n";
            continue;
        }

        y = 0;

        while(x>=((1LL)<<y)){
            if((x&((1LL)<<y))!=0){
                mini = min(y,mini);
            }
            ++y;
        }

        y = 0;

        while((x>=((1LL)<<y))||(n>=((1LL)<<y))){
            if((x&((1LL)<<y)) != (n&((1LL)<<y))){
                maxi = max(maxi,y);
            }
            ++y;
        }

        if(mini-maxi<=1){
            cout << "-1\n";
            continue;
        }

        int ans = 0;

        int z = (maxi+1);
        ans+=((1LL)<<z);
        while(n>=((1LL)<<z)){
            if((n&((1LL)<<z))!=0){
                ans+=((1LL)<<z);
            }
            ++z;
        }

        cout << ans << "\n";

    }

    return 0;}