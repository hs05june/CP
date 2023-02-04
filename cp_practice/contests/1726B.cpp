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

        ll n,m;
        cin >> n >> m;

        if(m<n){
            cout<<"NO\n";
            continue;
        }        

        ll a[n];
        ll z = m/n;
        for(int i = 0; i < n; i++){
            a[i] = z;
        }

        ll remain = m - (n*z);
        
        if(n & 1){
            a[0]+=remain;
        }
        else if((n%2)==0 && (remain%2)==0){
            a[0]+=(remain/2);
            a[1]+=(remain/2);
        }
        else{
            cout<<"NO\n";
            continue;
        }

        cout << "YES\n";
        for(ll i=0; i<n; i++){
            cout << a[i] << " ";
        }
        cout <<"\n";

    }

    return 0;}