//							  ੴ  ਵਾਹਿਗੁਰੂ 

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

char alag(char x, char y){
    if((x=='0' && y=='1') || (x=='1' && y=='0'))return '2';
    if((x=='0' && y=='2') || (x=='2' && y=='0'))return '1';
    if((x=='2' && y=='1') || (x=='1' && y=='2'))return '0';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,k;
    cin >> n >> k;

    deque<string> arr;

    rp(i,0,n){
        string x = "";
        rp(j,0,k){
            int c;
            cin >> c;
            x.pb(char('0'+c));
        }
        arr.pb(x);
    }

    sort(arr.begin(), arr.end());

    map<int,int> cnt;
    deq connected[n];

    rp(i,0,n){
        rp(j,0,n){
            if(i!=j){
            string z = "";
            rp(h,0,k){
                if(arr[i][h]==arr[j][h]){
                    z.pb(arr[i][h]);
                }
                else{
                    z.pb(alag(arr[i][h],arr[j][h]));
                }
            }
            auto l = lower_bound(arr.begin(),arr.end(),z);
            if((l-arr.begin())!=n && (*l)==z && (l-arr.begin())>j){
                cnt[i]++;
            } }
        }
    }

    ll ans = 0;

    for(auto i : cnt){
        if(i.s>=2){
            ans+=((i.s)*(i.s-1)/2);
        }
    }

    cout << ans << endl;

    return 0;}