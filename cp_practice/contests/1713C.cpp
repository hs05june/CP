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
    deque<ll> squares;
    for(ll i = 0; i*i <=101000; i++){
        squares.push_back(i*i);
    }

    while(t--){

        ll n;
        cin >> n;
        auto up = lower_bound(squares.begin(), squares.end(), n-1);
        ll z = up - squares.begin();
        
        ll ans[n] = {0};

        if(squares[z]==n-1){
            for(ll i = 0; i < n; i++){
                ans[i] = n - 1 - i;
            }
        }
        else{
            int visited[n] = {0};
            for(ll i = n-1; i >= 0; i--){
                ll x = squares[z] - i;
                if(x>=n || visited[x]==1){
                    --z;
                    while(visited[squares[z]-i]!=0){
                        --z;
                    }
                    ans[i] = squares[z] - i;
                    visited[squares[z]-i] = 1;

                }
                else{
                    ans[i] = x;
                    visited[x] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;}