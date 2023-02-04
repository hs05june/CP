// #include<bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define deq deque<int>
// #define mii map<int,int>
// #define pii pair<int,int>
// #define int ll
// #define all(x) (x).begin(), (x).end()
// int M = 1000000007;
// using namespace std;

// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){
//     int n;
//     cin >> n;

//     int arr[n];
//     int cnt[10]={0};

//     for(int i = 0; i < n; i++){
//         ll a; cin >> a;
//         arr[i] = a%10;
//         cnt[arr[i]]++;
//     }

//     int check[][3]={{1,1,1},{0,1,2},{0,0,3},{9,9,5},{9,8,6},{9,7,7},{9,4,0},{8,5,0},{7,6,0},{9,3,1},{8,4,1},{7,5,1},{6,6,1},{9,2,2},{8,3,2},{7,4,2},{6,5,2},{7,3,3},{6,4,3},{5,5,3},{5,4,4},{8,8,7}};

//     bool ans = false;

//     for(int i = 0; i < 22; i++){
//         mii z;
//         for(int j = 0; j<3;j++){
//             z[check[i][j]]++;
//         }
//         bool x = true;
//         for(auto j : z){
//             if(j.second>cnt[j.first]){
//                 x = false;
//                 break;
//             }
//         }
//         if(x){
//             ans = true;
//             break;
//         }
//     }

//     ans ? cout<<"YES\n":cout<<"NO\n";}

//     return 0;}

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
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

        mii m;

        for(ll i = 0; i <= 9; i++){
            m.insert({i,0});
        }

        ll n;
        cin >> n;

        for(ll i = 0 ; i < n; i++){
            ll x;
            cin >> x;
            m[(x%10)]++;
        }

        deq cnt;

        for(int i = 0; i < 10; i++){
            if(m[i]>=3){
                for(int j = 0; j < 3; j++){
                    cnt.push_back(i);
                }
            }
            else{
                for(int j = 0; j < m[i]; j++){
                    cnt.push_back(i);
                }

            }
        }

        bool ans = false;

        for(ll i = 0; i < cnt.size(); i++){
            for(ll j = i+1; j < cnt.size(); j++){
                for(ll k = j +1; k < cnt.size(); k++){
                    if((cnt[i]+cnt[j]+cnt[k])%10==3){
                        ans = true;
                    }
                }
            }
        }

        ans ? cout << "YES\n": cout << "NO\n";

    }

    return 0;}