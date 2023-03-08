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
const ll M = 998244353;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

int row[200007],column[200007],rowindex[200007],columnindex[200007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,m,k,q;
        cin >> n >> m >> k >> q;

        set<int> rows,columns;
        // mii row,column,rowindex,columnindex;

        rp(i,0,q){
            int x,y;
            cin >> x >> y;
            rows.insert(x);
            columns.insert(y);
            rowindex[x] = i+1;
            columnindex[y] = i+1;
            row[x] = y;
            column[y] = x;
        }

        if(columns.size() == m){
            int mini = q;
            for(auto i : columns){
                mini = min(columnindex[i],mini);
            }
            for(auto i : rows){
                if(rowindex[i]<mini){
                    row[i] = 0;
                }
            }
        }

        if(rows.size()==n){
            int mini = q;
            for(auto i : rows){
                mini = min(mini,rowindex[i]);
            }
            for(int i : columns){
                if(columnindex[i]<mini){
                    column[i] = 0;
                }
            }   
        }

        int ans = 0;

        for(int i : rows){
            if(row[i]==0)continue;
            ans++;
        }

        for(int i : columns){
            int x = column[i];
            if(column[i]==0 || row[x]==i)continue;
            else ans++;
        }

        cout << power(k,ans,M) << "\n";

    }

    return 0;}