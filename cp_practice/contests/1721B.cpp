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

int main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        ll n,m,sx,sy,d;
        cin >> n >> m >> sx >> sy >> d;

        // 1,m  n,1

        ll ans = (n-1) + (m-1);
        ll x1 = (sx-d) >= 1 ? (sx-d) : 1,x2 = (sx+d) <=n ? (sx+d) : n;
        ll y1 = (sy-d )>=1 ? (sy-d ) : 1,y2 = (sy+d)<=m ? (sy+d) : m;

        if((x1!=1 && y2!=m)||(x2!=n && y1!=1)){
            cout << ans << "\n";
        }
        else{
            cout << "-1\n";
        }

    }

    return 0;}