#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int ans = 0;

        for(int i = 1; i < n-2; i++){
            cout << i << " ";
            ans ^= i;
        }
        cout << (1<<29) << " " << (1<<30)<<" ";
        ans ^= (1<<29);
        ans ^= (1<<30);
        cout<<ans<<"\n";
    }

    return 0;}