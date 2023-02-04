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
        string a;
        cin >> a;

        string ans;

        for(int i = n-1; i >= 0; i--){
            if(a[i]=='0'){
                int x = a[i-1] - '0',y = a[i-2]-'0';
                int z = 10*y + x;
                char h = 'a' + z - 1;
                ans.push_back(h);
                i-=2;
            }
            else{
                char x = a[i] - '1' + 'a';
                ans.push_back(x);
            }
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<"\n";
    }

    return 0;}