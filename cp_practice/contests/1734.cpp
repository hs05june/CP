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

        int a[n];

        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        int ans = INT_MAX;

        for(int i = 0; i < n-2;i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j + 1; k < n; k++){
                    ans = min(ans,abs(a[j]-a[i]) + abs(a[k] - a[i]));
                    ans = min(ans,abs(a[i]-a[j])+abs(a[k]-a[j]));
                    ans = min(ans,abs(a[i]-a[k])+abs(a[j]-a[k]));
                }
            }
        }

        cout << ans << "\n";

    }

    return 0;}
