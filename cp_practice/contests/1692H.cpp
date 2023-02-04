#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
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

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n];
        rp(i,0,n)cin>>a[i];

        map<int,vector<pii>> poss;

        rp(i,0,n){
            int x = a[i];
            int z1 = i;
            while(i<n && a[i]==x){
                ++i;
            }
            --i;
            poss[x].pb({z1,i});
        }  
        int ans,i1,i2,maxi = 0;
        for(auto i : poss){
            for(int j = 0; j < sz(i.s); j++){
                int z = 0,x = (i.s)[j].f,y = (i.s)[j].s;
                z+= (y - x + 1);
                if(z>maxi){
                    ans = i.f;
                    i1 = x;
                    i2 = y;
                    maxi = z;
                }
                while((j+1)<sz(i.s) && (z - ((i.s)[j+1].f-(i.s)[j].s-1)) >= 0){
                    ++j;
                    z -= ((i.s)[j].f-(i.s)[j-1].s-1);
                    z+=((i.s)[j].s - (i.s)[j].f + 1);
                    y = (i.s)[j].s;
                    if(z>maxi){
                        ans = i.f;
                        i1 = x;
                        i2 = y;
                        maxi = z;
                    }
                }
            }

        }      
        cout << ans << " " << i1+1 << " " << i2+1  << endl;

    }

    return 0;}