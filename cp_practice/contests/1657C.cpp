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

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        ll n;
        cin >> n;
        
        string a;
        cin >> a;

        ll ans = 0,remain = n;

        for(ll i = 0; i < n; i++){
            if(a[i]=='('){
                if(i!=(n-1)){ans++;
                ++i;
                remain-=2;}
            }
            else if(a[i]==')'){
                ++i;
                ll z = 0;
                while(i < n && a[i]=='('){
                    ++i;++z;
                }
                if(i!=n){
                    ans++;
                    remain -= (z+2);
                    }
            }
        }

        cout << ans << " " << remain << "\n";

    }

    return 0;}