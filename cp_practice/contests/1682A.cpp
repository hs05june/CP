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

        if(n==1){cout<<"0\n";continue;}
        if((n%2)==1){
            int cen = n/2;
            int ans = 1;
            char x = a[cen];
            for(int i = cen+1; i < n; i++){
                if(a[i]==x)ans+=2;
                else break;
            }

            cout << ans << "\n";
            continue;
        }
        if(n%2==0){
            int cen1 = n/2;
            int cen2 = cen1-1;
            int ans = 2;
            char x = a[cen1];
            for(int i = cen1+1; i < n; i++){
                if(a[i]==x){
                    ans+=2;
                }
                else break;
            }
        cout << ans << "\n";
        continue;
        }
    }

    return 0;}