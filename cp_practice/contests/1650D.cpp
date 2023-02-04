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

        int ans[n+1] = {0};

        map<ll,ll> pos;

        for(int i = 1; i<=n; i++){
            int x;
            cin >> x;
            pos[x] = i;
        }

        for(int i = n; i >=1 ; i--){
            ans[i] = (i==pos[i]) ? 0 : pos[i];
            for(int j = 1; j<=n; j++){
                pos[j]-=ans[i];
                pos[j]+= pos[j]<=0 ? i : 0;
            }
        }

        for(int i = 1; i<=n; i++)cout <<ans[i] << " ";

        cout << "\n";
    }

    return 0;}