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

        ll n,x;
        cin >> n >> x;

        string a;
        cin >> a;
        ll maxi = (x-1)/2;
        ll cnt = 0;

        deque<ll> ones;
        ll num = 0;

        for(ll i = 0; i < n; i++){
            if(a[i]=='1'){
                num++;
                if(cnt != 0){
                    ones.push_back(cnt);
                }
                cnt = 0;
            }
            else if(a[i]=='0'){
                cnt ++;
            }
            
            if(i==(n-1)){
                if(cnt!=0){
                    ones.push_back(cnt);
                }
                cnt = 0;
            }
        }

        sort(all(ones));
        reverse(all(ones));

        for(ll i = 0; i < ones.size(); i++){
            if(x>=2*ones[i]+1){
                num += ones[i];
                x -= (2*ones[i]+1);
            }
            else{
                ll z = (x-1)/2;
                num += z;
                break;
            }
        }
        cout << num << endl;
    }

    return 0;}