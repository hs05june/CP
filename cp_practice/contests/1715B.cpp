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

int main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

    ll n,k,b,s;
    cin >> n >> k >> b >> s;


    if(s<k*b || s> (k*b + n*(k-1))){
        cout<<"-1\n";
        continue;
    }        
    else{
        ll ans[n]= {0};
        ans[0] = k*b;
        ll remain = s - (k*b);
        ll i = 1;

        while(remain>0 && i < n){
            if(remain>=(k-1)){
                ans[i]+=(k-1);
                remain -= (k-1);
            }
            else{
                ans[i]+=remain;
                remain = 0;
            }
            ++i;
        }

        ans[0]+=remain;

        for(ll i =0; i<n; ++i){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    }

    return 0;}