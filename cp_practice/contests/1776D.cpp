#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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

int spf[10000007];

void seive(){
    for(int i = 2; i<=10000000; i++){
        if(spf[i]==0){
            for(int j = i; j<=10000000; j+=i){
                spf[j] = i;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    seive();

    int t = 1;
    cin >> t;

    for(int tt = 1; tt <= t; tt++){
        
        int a,b;
        cin >> a >> b;

        if(__gcd(a,b)!=1){
            cout << "0\n";
            continue;
        }

        int diff = b - a;

        if(diff==1){
            cout << "-1\n";
            continue;
        }

        if((diff%2)==0){
            cout << "1\n";
            continue;
        }

        int ans = diff - (a%diff);
        
        while(diff!=1){
            ans = min(ans,spf[diff]-(a%spf[diff]));
            diff/=spf[diff];
        }
        cout << ans << "\n";
    }

    return 0;}