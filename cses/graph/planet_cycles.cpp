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

int arr[200007], ans[200007], levels[200007], parent[200007];
set<int> df;

void dfs(int n, int par){
    parent[n] = par;
    df.insert(n);
    if(ans[arr[n]]!=0){
        for(auto i : df){
            ans[i] = abs(levels[n]-levels[i]) + 1 + ans[arr[n]];
        }
        return;
    }
    if(levels[arr[n]]!=0){
        int k = abs(levels[n]-levels[arr[n]])+1;
        ans[n]=k;
        df.erase(n);
        int x = arr[n];
        while(x!=n){
            ans[x] = k;
            df.erase(x);
            x = arr[x];
        }
        for(auto i : df){
            ans[i] = abs(levels[arr[n]]-levels[i]) + k;
        }
        return;
    }
    else{
        levels[arr[n]] = 1 + levels[n];
        dfs(arr[n],n);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rp(i,0,n+1){
        arr[i] = ans[i] = 0;
    }

    rp(i,1,n+1){
        cin >> arr[i];
    }

    rp(i,1,n+1){
        if(levels[i]==0){
            df.clear();
            levels[i] = 1;
            dfs(i,0);
        }
    }

    rp(i,1,n+1){
        cout << ans[i] << " ";
    }

    return 0;}