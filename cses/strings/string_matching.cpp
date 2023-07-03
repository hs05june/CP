#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    string a,b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    string str = b + ";" + a;

    int pi[n+m+1];
    pi[0] = 0;

    int j = 0, i = 1;

    while(i < str.size()){
        if(str[i] == str[j]){
            ++j;
            pi[i] = j;
            ++i;
        }
        else{
            if(j==0){
                pi[i] = 0;
                ++i;
            }
            else{
                j = pi[j-1];
            }
        }
    }

    int ans = 0;
    rp(i,0,n+m+1)ans += (pi[i]==m);
    
    cout << ans << "\n";

    return 0;}