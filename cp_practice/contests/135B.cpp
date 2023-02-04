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

        if(n==1){cout<<1<<"\n";continue;}

        if(n==2){cout<<"1 2\n";continue;}

        if(n==3){cout << "3 1 2\n";continue;}

        int a[n];

        if(n%2==0){
            a[n-1] = n;
            a[n-2] = n-1;

            for(int i = 0; i < n-2;i++){
                a[i] = n-2-i;
            }
        }

    if(n%2==1){
        a[0] = 1,a[1] = 2,a[2] = 3;

        a[n-1] = n,a[n-2] = n-1;

        for(int i = 3; i < n-2; i++){
            a[i] = n+1-i;
        }
    }

    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    }

    return 0;}