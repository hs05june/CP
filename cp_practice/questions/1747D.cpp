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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        int n,q;
        cin >> n >> q;
        int arr[n+1],pref_sum[n+1],pref_xor[n+1];
        pref_xor[0] = pref_sum[0] = arr[0] = 0;

        rp(i,1,n+1)cin >> arr[i];

        map<int,deq> num[2];

        rp(i,1,n+1){
            pref_sum[i] = pref_sum[i-1] + arr[i];
            pref_xor[i] = pref_xor[i-1] ^ arr[i];
            num[(i%2)][pref_xor[i]].pb(i);
        }

        while(q--){
            int l,r;
            cin >> l >> r;
            if((pref_sum[r]-pref_sum[l-1])==0){
                cout << "0\n";
                continue;
            }
            if(((pref_xor[r] ^ pref_xor[l-1]) != 0) || (r-l+1<=2)){
                cout << "-1\n";
                continue;
            }
            if(((r-l+1) & 1) || arr[l]==0 || arr[r]==0){
                cout << "1\n";
                continue;
            }
            auto itr = lower_bound(all(num[(l%2)][pref_xor[l-1]]),l);
            if(itr==num[(l%2)][pref_xor[l-1]].end() || (*itr)>r)cout << "-1\n";
            else cout << "2\n";
        }

    }

    return 0;}