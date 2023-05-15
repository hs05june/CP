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

    int n;
    cin >> n;
    int arr[n+1], preffix[n+1];
    arr[0] = preffix[0] = 0;
    rp(i,1,n+1)cin >> arr[i];
    rp(i,1,n+1)preffix[i] = preffix[i-1] + arr[i];
    mii cnt;
    rp(i,1,n+1){int z = preffix[i]%n; if(z<0)z+=n; cnt[z%n]++;}
    int ans = 0;    

    int x = 0;

    rp(i,1,n+1){
        ans+=cnt[x];
        int z = preffix[i]%n; 
        if(z<0)z+=n;
        cnt[z%n]--;
        x+=arr[i];
        x%=n;
        if(x<0)x+=n;
        x%=n;
    }

    cout << ans << "\n";

    return 0;}