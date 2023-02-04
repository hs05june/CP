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

        int n;
        cin >> n;

        string a;
        cin >> a;

        ll sum = 0;

        for(int i = 0; i < n; i++){
            sum += a[i]=='L' ? i : (n - 1 - i);
        }

        ll ans[n], z = 0;

        for(int i = 0; i < (n/2); i++){
            if(a[i]=='L'){
                sum = sum - i + (n - 1 - i);
                ans[z] = sum;
                ++z;
            }

            if(a[n-1-i]=='R'){
                sum = sum - i + (n - 1 - i);
                ans[z] = sum;
                ++z;
            }
        }
        for(ll i = z; i < n; i++){
            ans[i] = sum;
        }

        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }

        cout << "\n";
    }

    return 0;}