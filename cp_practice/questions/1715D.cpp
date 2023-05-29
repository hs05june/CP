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

    int n,q;
    cin >> n >> q;

    int arr[n+1];
    rp(i,0,n+1)arr[i] = 0;

    map<int,vector<pii>> ele;
    set<int> already;

    while(q--){
        int i, j, x;
        cin >> i >> j >> x;
        if(i==j){
            arr[i] = x;
            already.insert(i);
            continue;
        }
        ele[i].pb({j,x});
        ele[j].pb({i,x});
    }

    rep(i,n,1){
        if(already.count(i))continue;
        if(sz(ele[i])==0)continue;
        int z = 0;
        for(auto j : ele[i]){
            int x = (j.s ^ arr[j.f]);
            z |= (x);
        }
        arr[i] = z;
        for(auto j : ele[i]){
            arr[i] &= (j.s);
        }
    }

    rp(i,1,n+1){
        if(already.count(i))continue;
        set<int> require;
        for(auto j : ele[i]){
            if(j.f==i)continue;
            rp(k,0,30){
                if((((1<<k) & (j.s))!=0) && (((1<<k) & (arr[j.f]))==0))require.insert(k);
            }
        }
        rp(j,0,30){
            if(((1<<j) & arr[i])!=0 && (!require.count(j)))arr[i] -= (1<<j);
        }
    }

    rp(i,1,n+1)cout << arr[i] << " ";
    cout << "\n";

    return 0;}