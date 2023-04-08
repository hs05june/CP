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

int arr[100007],brr[100007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        rp(i,0,n){
            cin >> arr[i];
        }

        rp(i,0,n){
            cin >> brr[i];
        }
        
        int ans = 0; 

        for(int i = 29; i >= 0 ; i--){
            int x = (ans | ((1LL)<<i));
            mii cnta,cntb;
            rp(i,0,n){
                cnta[arr[i] & x]++;
            }
            rp(i,0,n){
                cntb[brr[i] & x]++;
            }
            bool check = true;
            for(auto j : cnta){
                if(j.s != cntb[(x ^ (j.f))])check = false;
            }
            for(auto j : cntb){
                if(j.s != cnta[(x ^ (j.f))])check = false;
            }
            if(check){
                ans|=(1<<i);
                }
        }

        cout << ans << "\n";

    }

    return 0;}