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
deq factorial;

int solve(int n, int index){
    if(index>=14 || n < factorial[index]){
        return __builtin_popcountll(n);
    }
    return min(solve(n,index+1),1 + solve(n-factorial[index],index+1));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    int num = 1,i = 1;

    while(num<=1000000000000){
        factorial.pb(num);
        ++i;
        num*=i;
    }

    while(t--){
        int n;
        cin >> n;
        cout << solve(n,0) << "\n";
    }

    return 0;}