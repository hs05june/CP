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

        ll n,l,r;
        cin >> n >> l >> r;

        ll ans[n];
        bool possible = true;

        for(int i=0; i<n; i++){
            ll z = r%(i+1);
            if(r-z>=l){
                ans[i] = r-z;
            }
            else{
                possible = false;
                break;
            }
        }

        if(possible){
            cout<< "YES\n";
            for(int i = 0; i<n; i++){
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;}