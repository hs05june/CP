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

int cnt[1000007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n];
        set<int> uniq;
        rp(i,0,n){cin >> arr[i];cnt[arr[i]]++;uniq.insert(arr[i]);}

        deq num;
        int ans = 0;
        for(auto i : uniq){num.pb(i);ans+=(cnt[i]*(cnt[i]-1)*(cnt[i]-2));}
       
        // for(int i = 2; i*i <= num.back() ; i++){
        //     if(num[0]*i*i > num[sz(num)-1])break;
        //     for(auto j : num){
        //         int x = j*i;
        //         int y = x*i;
        //         if(y > num[sz(num)-1])break;
        //         ans += (cnt[j] * cnt[x] * cnt[y]);
        //     }
        // }
        // cout << ans << "\n";
        for(auto i : num){
            for(int j = 1; j * j <= i; j++){
                if((i%j)==0){
                    int x = i/j;
                    if(j!=1 && i*j<=1000000)ans+=(cnt[i/j]*cnt[i]*cnt[i*j]);
                    if(x!=1 && j!=x && i*x<=1000000)ans+=(cnt[i/x]*cnt[i]*cnt[i*x]);
                }
            }
        }

        cout << ans << "\n";

        rp(i,0,n)cnt[arr[i]]--;
    }

    return 0;}