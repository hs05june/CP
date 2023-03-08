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

        int a,b;
        cin >> a >> b;

        int x = -1,y = -1;
        int i=0;
        while((1<<i)<=a){
            if(((1<<i)&a)!=0 && ((1<<i)&b)==0){
                x = max(i,x);
            }
            ++i;
        }

        if(x==-1){
            cout << "1\n";
            continue;
        }

        i = x+1;
        int z = 0;
        while((1<<i)<=b){
            if(((1<<i)&b)!=0 && ((1<<i)&a)==0){
                if(y==-1)y = i;
            }
            if(((1<<i)&b)!=0)z|=(1<<i);
            ++i;
        }
        i = x;
        while(i>=0){
            if(((1<<i)&a)!=0)z|=(1<<i);
            --i;
        }

        int ans1 = z - b;
        if(z!=a)ans1++;

        i = y;int h = 0;
        h|=(1<<y);
        while((1<<i)<=a){
            if(((1<<i)&a)!=0)h|=(1<<i);
            ++i;
        }
        int ans2 = h - a;
        if(h!=b)ans2++;
        cout << min(ans1,ans2) << "\n";
    }

    return 0;}