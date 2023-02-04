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

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        ll k,x;
        cin >> k >> x;

        ll z1 = k*(k+1)/2, z2 = k*(k-1)/2;

        if(x >= (z1+z2)){
            cout << (2*k) - 1 << "\n";
            continue;    
        }

        if(x==z1){
            cout << k <<"\n";
            continue;
        }

        if(x<=z1){
            ll low = 1,high = k;
            while(high>low){
                ll mid = (low+high)/2;
                
                if((mid*(mid+1)/2)<x){
                    low = mid+1;
                }
                else if((mid*(mid+1)/2)>=x){
                    high = mid;
                }                
            }
            cout << high << "\n";
            continue;
        }

        if(x>z1){
            x-=z1;
            ll low = 1,high = k-1;

            while(high>low){
                ll mid = (low + high)/2;
                if((mid*((2*k)-mid-1)/2)<x){
                    low = mid + 1;
                }
                else if((mid*((2*k)-mid-1)/2)>=x){
                    high = mid;
                }
            }
            cout << (high + k) << "\n";
        }

    }

    return 0;}