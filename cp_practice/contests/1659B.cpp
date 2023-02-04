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

        ll n,k;
        cin >> n >> k;

        string a;
        cin >> a;

        ll ans[n] = {0};

        if(k&1){
            ll z = n-1;
            for(int i = 0; i < n; i++){
                if(a[i]=='1'){
                    z=i;
                    break;
                }
            }
            ans[z]++;--k;
            for(int i = 0; i < n; i++){
                if(i!=z){
                    a[i] = a[i]=='1' ? '0' : '1';
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(k > 0 && a[i]=='0'){
                ans[i]++;
                --k;
                a[i]='1';
            }
        }

        ans[n-1]+=k;
        if(k & 1){
            a[n-1] = '0';
        }
        cout << a << "\n";

        for(int i = 0; i < n; i++)cout << ans[i] <<" ";
        cout << " \n";

    }
    return 0;}