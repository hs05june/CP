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

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        ll n;
        cin >> n;

        ll r[3],c[3];

        map<ll,int> r1,c1;

        for(int i = 0; i < 3; i++){
            cin >> r[i] >> c[i];
            r1[r[i]]++;
            c1[c[i]]++;
        }

        ll rx,cx,ry,cy;

        for(auto i : r1){
            if(i.second == 2)rx = i.first;
            else ry = i.first;
        }
        for(auto i : c1){
            if(i.second == 2)cx = i.first;
            else cy = i.first;
        }

        ll x,y;
        cin >> x >> y;

        bool jump = true;

        if((rx==1 && cx==1) || (rx==1 && cx==n) || (rx==n && cx==1) || (rx==n && cx==n) ){
            jump = false;
        }

        if(!jump){
            rx==x || cx==y ? cout << "YES\n": cout << "NO\n";
        }
        else{
        (rx%2==x%2) || (cx%2==y%2) ? cout << "YES\n": cout << "NO\n";}

    }

    return 0;}