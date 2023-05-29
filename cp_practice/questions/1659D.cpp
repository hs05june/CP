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
        int sum = 0;
        int a[n+1];
        a[0] = 0;
        rp(i,1,n+1){cin >> a[i];sum += a[i];}

        int one = sum/n;
        int zero = n - one;

        int ans[n+1];
        ans[0] = 0;

        int location[n+1];
        rp(i,0,n+1)location[i] = 0;
        int x = 0, left = 0;
        rep(i,n,zero+1){
            if(a[i]==n)ans[i] = 1;
            else {
                ans[i] = 0;
                ++x;
                left++;
                location[x] = i;
            }
        }  

        if(left==0){
            rp(i,1,zero+1)ans[i] = 0;
        }
        else{
            rep(i,zero,1){
                int y = zero - i + 1;
                if(a[i]==(location[y]-1))ans[i] = 1;
                else{
                    ans[i] = 0;
                    ++x;
                    location[x] = i;
                }
            }          
        }

        rp(i,1,n+1)cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;}