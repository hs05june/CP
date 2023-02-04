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
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
const ll M = 1000000007;
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    mii ans;

    while(t--){

        char x;
        cin >> x;

        if(x=='+'){
            int n;
            cin >> n;
            for(int i = 2*n;;i+=n){
                if(ans[i]==0 || ans[i]==i){
                    ans[n] = i;
                    ans[i]=i;
                    break;
                }
            }
        }

        if(x=='?'){
            int n;
            cin >> n;
            if(ans[n]==0){
                cout << n << "\n";
                ans[n] = n;
            }
            else{
            for(int i = ans[n];;i+=n){
                if(ans[i]==0 || ans[i]==i){
                    ans[i] = i;
                    ans[n] = i;
                    cout << i << "\n";
                    break;
                }
            }
            }
        }
    }

    return 0;}