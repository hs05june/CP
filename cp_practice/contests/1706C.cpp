#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

int n;
ll dp[100007][2];
ll solve(int a[],int i,int check){
    if(i>=(n-1)){
        return 0;
    }

    if(dp[i][check]!=-1){
        return dp[i][check];
    }

    ll ans = LLONG_MAX;
    ll x = max(a[i-1],a[i+1]);
    ll z = x>=a[i] ? x-a[i]+1 : 0;
    ans = min(ans,z+solve(a,i+2,check));
    if(check==0)ans = min(ans,z+solve(a,i+3,1));

    return dp[i][check] = ans;
}

int main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){
        memset(dp,-1,sizeof(dp));
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        ll ans = 0;
        if(n&1){
            for(int i = 1; i < n; i+=2){
                int z = max(a[i-1],a[i+1]);
                ans+= (z>=a[i]) ? (z-a[i]+1) : 0;
            }
        }
        else{
        ans = LLONG_MAX;
        ans = min(solve(a,1,0),ans);
        ans = min(solve(a,2,1),ans);}
        cout  << ans << "\n";
    }

    return 0;}