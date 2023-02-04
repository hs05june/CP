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

        int n;
        cin >> n;

        int x[n],y[n];

        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        for(int i = 0; i < n; i++){
            cin >> y[i];
        }

        deq neg,pos;

        for(int i = 0; i < n; i++){
            if(y[i]-x[i]<0)neg.push_back(y[i]-x[i]);
            else pos.push_back(y[i]-x[i]);
        }

        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());
        reverse(pos.begin(), pos.end());
        
        int index = 0,ans = 0;

        for(int i = 0; i < neg.size(); i++){
            if(index < pos.size() && abs(neg[i])<=abs(pos[index])){
                index++;
                ans++;
            }
        }

        int remaining = pos.size() - index;

        ans += (remaining/2);

        cout << ans << "\n";

    }

    return 0;}