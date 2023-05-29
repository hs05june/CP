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
    cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        int arr[n+1][m+1];        

        map<int,deq> cnt;

        rp(i,1,n+1){
            int ans = 0;
            rp(j,1,m+1){
                cin >> arr[i][j];
                ans += (j*arr[i][j]);
            }
            cnt[ans].pb(i);
        }

        int index,a,b;

        for(auto i : cnt){
            if(sz(i.s)==1){
                index = i.s.back();
                a = i.f;
            }
            else b = i.f;
        }

        cout << index << " " << abs(a-b) << '\n';

    }

    return 0;}