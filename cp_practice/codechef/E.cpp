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

        int n;
        cin >> n;

        int c[n];

        for(int i = 0; i < n; i++){
            cin >> c[i];
        }
        deq a[2];
        a[0].push_back(c[0]);
        ll z = c[0];
        int turn = 0;
        
        for(int i = 1; i < n; i++){
            if(c[i]>z){
                turn = (turn + 1)%2;
                z = c[i];
            }
            a[turn].push_back(c[i]);
        }

        if(a[0].empty() || a[1].empty()){
            cout << "-1\n";
            continue;
        }
        cout << a[0].size()<<"\n";

        for(int i = 0; i < a[0].size(); i++){
            cout << a[0][i]<<" ";
        }
        cout << "\n" << a[1].size() << "\n";
        for(int i = 0; i < a[1].size(); i++){
            cout << a[1][i]<<" ";
        }

    }

    return 0;}