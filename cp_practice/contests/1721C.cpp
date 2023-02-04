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
        int a[n],b[n];
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        for(int i = 0; i < n; i++){
            int ans = *(lower_bound(b,b+n,a[i]));
            cout << (ans - a[i]) << " ";
        }
        cout << "\n";

        int maxi = b[n-1];
        int ans[n];
        ans[n-1] = (maxi-a[n-1]);
        for(int i = n-2; i >= 0; i--){
            if(b[i]>=a[i+1]){
                ans[i] = (maxi - a[i]);
            }
            else{
                maxi=b[i];
                ans[i] = (maxi-a[i]);
            }
        }

        for(int i = 0 ; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;}