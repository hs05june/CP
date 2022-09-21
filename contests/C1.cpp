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

        ll n;
        cin >> n;
        map<ll,ll> cnt;

        int a[n];

        for(int i = 0; i < n; i++){
            cin >> a[i];
            cnt[a[i]] ++;
        }
        ll b[n];
        sort(a, a + n);
        int j = 0;

        for(int i = 0; i < n/2; i++){
            b[i] = a[j];
            j+=2; 
        }

        j = 1;

        for(int i = n-1; i > n/2; i--){
            b[i] = a[j];
            j+=2;
        }

        b[n/2] = a[n-1];

        ll ans1 = 1;

        for(int i = 0; i < n; i++){
            ll check = 1;
            while((i+1)<n && b[i]<b[i+1]){
                check++;
                ++i;
            }
            ans1=max(ans1,check);
        }
        ll ans2 = 1;
        reverse(b,b+n); 
        for(int i = 0; i < n; i++){
            ll check = 1;
            while((i+1)<n && b[i]<b[i+1]){
                check++;
                ++i;
            }
            ans2=max(ans2,check);
        } 
        cout << min(ans1,ans2) << "\n";
    }

    return 0;}