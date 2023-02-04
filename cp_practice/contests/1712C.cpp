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

        ll arr[n];

        for(ll i=0; i<n; i++){
            cin >> arr[i];
        }

        set<ll> to_make_zero,encountered;

        ll ans = 0;
        bool correct = true;

        for(int i = 0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                correct = false;
                break;
            }
        }

        if(correct){
            cout << "0\n";
            continue;
        }

        to_make_zero.insert(arr[0]);

        for(int i = 1; i<n; i++){
            if(to_make_zero.count(arr[i]) || (arr[i] < arr[i-1])){
                for(auto j : encountered){
                    to_make_zero.insert(j);
                }
                encountered.clear();
            }
            encountered.insert(arr[i]);
        }

        cout << to_make_zero.size()<< "\n";

    }

    return 0;}