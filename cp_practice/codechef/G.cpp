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
#define int long long
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

        ll n,k;

        cin >> n >> k;

        string a;
        cin >> a;
        string b;
        b = a;
        bool all_one = true,all_zero = true;

        for(int i = 0; i < a.length(); i++){
            if(a[i]=='0')all_one = false;
            if(a[i]=='1')all_zero = false;
        }

        if(all_one || all_zero){
            for(int i = 0; i < a.length(); i++){
                cout << '0';
            }
            cout << "\n";
            continue;
        }

        for(int i = 0; i < b.length(); i++){
            if(b[i]=='1')a[i] = '0';
            else if(b[i]=='0'){
                if((i>0 && b[i-1]=='1') || (i<(n-1) && b[i+1]=='1')){
                    a[i]='1';
                }
            }
        }
        --k;

        int movement[n] = {0};
        deq zeros,ones;

        for(int i = 0; i < a.length(); i++){
            if(a[i]=='0'){
                zeros.push_back(i);
            }
            if(a[i]=='1'){
                ones.push_back(i);
            }
        }

        for(int i = 0; i < a.length(); i++){
            if(a[i]=='0'){
                auto itr1 = lower_bound(ones.begin(),ones.end(),i);
                auto itr2 = itr1-1;
                if(itr1==ones.end()){
                    movement[i] = i - (*itr2) ;
                }
                else if(itr2<ones.begin()){
                    movement[i] = (*itr1)-i;
                }
                else{
                    movement[i] = min(abs(i - (*itr2)),abs((*itr1)-i));
            }
            if(a[i]=='1'){
                auto itr1 = lower_bound(zeros.begin(),zeros.end(),i);
                auto itr2 = itr1-1;
                if(itr1==zeros.end()){
                    movement[i] = i - (*itr2) ;
                }
                else if(itr2<zeros.begin()){
                    movement[i] = (*itr1)-i;
                }
                else{
                    movement[i] = min(abs(i - (*itr2)),abs((*itr1)-i));
                }
            }
        }

        char ans[n];
        for(int i = 0 ; i < n; i++){
            if(k-movement[i]<0){ans[i]=a[i];}
            else{
            if(a[i]=='1'){
                ans[i] = (k-movement[i]+1)%2 == 0 ? '1' : '0';
            }
            else if(a[i]=='0'){
                ans[i] = (k-movement[i]+1)%2 == 0 ? '0' : '1';
            }}
        }

        for(int i = 0; i < n; i++){
            cout << ans[i];
        }
        cout << "\n";
    }

    return 0;}