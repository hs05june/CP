#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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
using namespace std;

int power(int a, int b){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans * 1LL * a);}
        a = (a * 1LL * a);
        b >>= 1;}
    return ans;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    string a;
    cin >> a;

    int n = a.size();
    map<char,int> hashing;

    set<char> uniq;
    for(auto i : a)uniq.insert(i);

    int x = 1;
    for(auto i : uniq){
        hashing[i] = x;
        ++x;
    }

    // for(auto i : hashing){
    //     cout << i.f << " " << i.s << "\n";
    // }

    int preff[n+1];
    preff[0] = 0;

    rp(i,1,n+1){
        // preff[i] = ((preff[i-1]%M * x%M)%M + hashing[a[i-1]]%M)%M;
        preff[i] = preff[i-1] * x + hashing[a[i-1]];
    }

    // rp(i,0,n+1)cout << preff[i] << " ";
    // cout << "\n";

    int ans = 1, good = preff[n];

    rp(i,1,n+1){
        int y = preff[i-1] * power(x,n-i+1);
        int value = preff[n] - y;
        // cout << preff[n] << ' ' << preff[i-1] << " " << value << "\n";
        value = value * power(x,i-1);
        value = value + preff[i-1];
        if(value < good){
            ans = i;
        }
        // cout << value << "\n";
    }

    string str = "";
    int z = ans - 1;

    rp(i,z,n)str.pb(a[i]);
    rp(i,0,z)str.pb(a[i]);

    cout << str << "\n";

    return 0;}