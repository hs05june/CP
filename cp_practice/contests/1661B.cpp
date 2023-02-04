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
int M = 32768;
using namespace std;

signed main(){
    CODE BY HARPREET

    ll n; 
    cin >> n;

    ll a[n];

    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        int ans = 15;
        for(int j = 0; j <=15; j++){
            int test = 0;
            ll z = a[i];
            for(int k = 0; k < j; k++){
                z = (z+1)%M;
                test++;
                if(z==0){
                    break;
                }
            }
            if(z!=0){
                for(int k = 0; k < 15 - j; k++){
                    z = (2*z)%M;
                    test++;
                    if(z==0){
                        break;
                    }
                }
            }
            ans = min(ans,test);
        }

        cout << ans << " ";
    }

    return 0;}