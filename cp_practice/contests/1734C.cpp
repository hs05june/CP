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

        int n;
        cin >> n;

        string a;
        cin >> a;

        a = 'H' + a; 

        int made_zero[n+1] = {0};
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == '0'){
                for(int j = i; j <= n; j+=i){
                    if(a[j]=='1')break;
                    else if(a[j]=='0' && made_zero[j] == 0){
                        ans += i;
                        made_zero[j] = 1;
                    }
            }
        }
    }
    cout << ans << "\n";
    }
    return 0;}