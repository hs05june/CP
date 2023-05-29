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

        int n;
        cin >> n;

        int a[n+1], b[n+1];

        mii store[n+1];
        set<int> store1[n+1];

        map<pii,int> index;
        
        rp(i,1,n+1){
            cin >> a[i];
        }

        rp(i,1,n+1){
            cin >> b[i];
            store[a[i]][b[i]]++;
            store1[a[i]].insert(b[i]);
        }

        // for(auto i : store[3])cout << i.f << " " << i.s << "\n";

        int ans = 0;
        
        rp(i,1,n+1){
            rp(j,i,n+1){
                // cout << i << " " << j << "\n";
                if(i*j>2*n)break;
                for(auto k : store1[i]){
                    // if(i*j - k > n)break;
                    // if(i*j - k <= 0)continue;
                    int po = i*j - k;
                    // cout << i << " " << j << " " << po << "\n";
                    if(store[j].count(po)){
                        index[{i,k}]+=store[j][po];
                        if(i!=j || po!=k)index[{j,po}]+=store[i][k];
                    }
                }
            }
        }

        for(auto i : index){
            // cout << i.f.f << " " << i.f.s << " = " << i.s << "\n"; 
            ans += i.s;
        }

        // rp(i,0,n){
        //     ans+=index[{a[i],b[i]}];
        // }

        cout << ans << "\n";

    }

    return 0;}