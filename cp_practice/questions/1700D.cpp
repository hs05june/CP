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

int n;
long double volume[200007], preffix[200007], maxi[200007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        cin >> n;
        rp(i,1,n+1)cin >> volume[i];
        rp(i,1,n+1)preffix[i] = volume[i] + preffix[i-1];
       
       vector<long double> answers;

       rp(i,1,n+1){
            maxi[i] = max(maxi[i-1], (preffix[i]/i));
       }

       rp(i,1,n+1){
            long double x = max(maxi[i], preffix[n]/i);
            answers.pb(-x);
       }

        int q;
        cin >> q;

        while(q--){
            int x;
            cin >> x;
            auto itr = lower_bound(all(answers),-x);
            int z = (itr - answers.begin());
            if(itr==answers.end())cout << "-1\n";
            else cout << z+1 << "\n";
        }

    }

    return 0;}