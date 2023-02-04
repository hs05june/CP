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

        if(n==1){
            cout<<"1\n";
            continue;
        }

        else if(n==2){
            cout<<"1\n1 1\n";
            continue;
        }

        else {
            cout<<"1\n1 1\n";

            for(int i = 3; i<=n;i++){
                cout<<"1 ";
                for(int j = 1; j<=i-2; j++){
                    cout<<"0 ";
                }
                cout<<"1\n";
            }
        }
        }
    

    return 0;}