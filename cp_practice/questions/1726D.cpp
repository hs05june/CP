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

int parent[1000007], Size[1000007];

int Find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    int x = Find(a), y = Find(b);
    if(Size[x] > Size[y])swap(x,y);
    parent[x] = y;
    Size[y] += Size[x];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        string ans = "";

        rp(i,0,n+1){
            parent[i] = i;
            Size[i] = 1;
        }

        pii arr[m];

        rp(i,0,m){
            int a, b;
            cin >> arr[i].f >> arr[i].s;
            if(Find(arr[i].f)==Find(arr[i].s))ans.pb('1');
            else{
                ans.pb('0');
                Union(arr[i].f,arr[i].s);
            }
        }

        int cnt = 0;

        for(auto i : ans){
            cnt += (i == '1');
        }

        if(cnt <= 2){
            cout << ans << "\n";
            continue;
        }

        rp(i,1,n+1){
            parent[i] = i;
            Size[i] = 1;
        }

        bool check = true;
        int ind;
        set<int> done;
        rp(i,0,m){
            if(ans[i]=='1'){
                int x = Find(arr[i].f), y = Find(arr[i].s);
                if(x==y){
                    check = false;
                    ind = i;
                    ans[i] = '0';
                    break;    
                }
                Union(arr[i].f,arr[i].s);
                done.insert(i);
            }
        }
        
        if(check){
            cout << ans << "\n";
            continue;
        }
        rp(i,1,n+1){
            parent[i] = i;
            Size[i] = 1;
        }
        Union(arr[ind].f, arr[ind].s);
        rp(i,0,m){
            if(ans[i]=='1')continue;
            int x = Find(arr[i].f), y = Find(arr[i].s);
            if(x==y){
                ans[i] = '1';
                break;
            }
            Union(arr[i].f,arr[i].s);
        }
        cout << ans << "\n";

    }

    return 0;}