#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 998244353;
using namespace std;

map<pii,ll> dp;

ll solve(ll n, ll k,ll x){

    if(x==n)return 1%M;
    if(x>n)return 0;

    if(dp.count({k,x}))return dp[{k,x}];

    ll ans = 0;

    for(ll i = x+k;i<=n;i+=k){
        if(i>n)break;
        ans = ((ans%M) + (solve(n,k+1,i)%M))%M;
    }
    dp.insert({{k,x},(ans%M)});
    return (ans%M);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // memset(dp,-1,sizeof(dp));
    int n,k;
    cin >> n >> k;

    for(ll i = 1; i<=n; i++){
    cout<<(solve(i,k,0)%M)<<" ";
    }
    return 0;}