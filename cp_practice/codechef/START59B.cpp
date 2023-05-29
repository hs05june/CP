#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;
// int setBitNumber(int n)
// {
//     // Below steps set bits after
//     // MSB (including MSB)
 
//     // Suppose n is 273 (binary
//     // is 100010001). It does following
//     // 100010001 | 010001000 = 110011001
//     n |= n >> 1;
 
//     // This makes sure 4 bits
//     // (From MSB and including MSB)
//     // are set. It does following
//     // 110011001 | 001100110 = 111111111
//     n |= n >> 2;
//     n |= n >> 4;
//     n |= n >> 8;
//     n |= n >> 16;
//     // n
//     n = ((n + 1) >> 1) |
//         (n & (1 << ((sizeof(n) * CHAR_BIT)-1)));
//     return n;
// }
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    // cout << 63 - __builtin_clzll(4) << "\n";

    // set<int> powers;
    // int z = 0;
    // while((1<<z)<=1000000000000000006){
    //     powers.insert(((1<<z)-1));
    //     ++z;
    // }

    while(t--){

        int l,r;
        cin >> l >> r;

        if(l==0 && r==0){
            cout << "0\n";
            continue;
        }

        if(l==0){
            int maxir = 63 - __builtin_clzll(r);
            // long double z = log2(r+1);
            cout << ((1LL)<<(maxir+1)) << "\n";
            continue;
        }

        int maxil = 63 - __builtin_clzll(l), maxir = 63 - __builtin_clzll(r);


        if(maxil==maxir){
            cout << "0\n";
            continue;
        }

        int ans = 0;
        int low = maxil+1;
        int x = ((1LL)<<low) - l;
        ans+=((maxir-maxil)*x);
        // cout << x << " " << ans << "\n";
        while(low<maxir){
            int x = ((1LL)<<low);
            ans+=((maxir-low)*x);
            // cout << x << " " << ans << "\n";
            ++low;
        }
        cout << ans << "\n";
    }

    return 0;}