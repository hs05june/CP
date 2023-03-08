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

int num(char x){
    if(x=='m' || x=='M')return 0;
    if(x=='e' || x=='E')return 1;
    if(x=='o' || x=='O')return 2;
    if(x=='w' || x=='W')return 3;
    return 4;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string a;
        cin >> a;
        int cnt[4][2];
        rp(i,0,4){
            cnt[i][0] = LLONG_MAX;
            cnt[i][1] = LLONG_MIN;
        }

        bool ans = true;

        rp(i,0,n){
            int x = num(a[i]);
            if(x==4){
                ans = false;
                break;
            }
            cnt[x][0] = min(i,cnt[x][0]);
            cnt[x][1] = max(i,cnt[x][1]);
        }

        if(!ans || cnt[0][0]!=0 || cnt[3][1]!=(n-1)){
            cout << "NO\n";
            continue;
        }
        for(int i = 1; i < 4; i++){
            if((cnt[i][0]-cnt[i-1][1])!=1){
                ans = false;
                break;
            }
        }

        (ans) ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;}