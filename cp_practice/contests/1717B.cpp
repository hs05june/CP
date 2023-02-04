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

        int n,k,r,c;
        cin >> n >> k >> r >> c;

        char ans[n][n];
        // ans[r-1][c-1] = 'X';

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = '.';
            }
        }

        ans[r-1][c-1] = 'X';
        int x = 0;

        for(int i = c-1; i >= 0; i-=k){
            ans[r-1][i] = 'X';
            x = i;
        }

        for(int i = c-1; i < n; i+=k){
            ans[r-1][i] = 'X';
        }

        int t = x;
        for(int i = r-2; i >= 0; i--){
            t--;
            if(t<0){t=k-1;}
            for(int j = t; j < n;j+=k){
                ans[i][j] = 'X';
            }
        }

        for(int i = r; i<n;i++){
            x++;
            if(x==k)x=0;
            for(int j = x; j < n; j+=k){
                ans[i][j] = 'X';
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<ans[i][j];
            }
            cout<<"\n";
        }

    }

    return 0;}