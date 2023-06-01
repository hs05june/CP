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

    int n,m;
    cin >> n >> m;

    string a[n];
    rp(i,0,n)cin >> a[i];

    int cnt[n][3], seen[n][m];
    rp(i,0,n)cnt[i][0] = cnt[i][1] = cnt[i][2] = 0;
  
    rp(i,0,n){
        rp(j,0,m)cnt[i][2]+=(a[i][j]=='1');
    }

    rp(i,0,n){
        rp(j,0,m){
            int x = 0;
            while (j < m && a[i][j] == '1')
            {
                ++x;
                ++j;
            }
            if(x!=0)--j;
            cnt[i][1] += (x/2);
        }
    }

    rp(i,0,n){
        rp(j,0,m){
            int x = 0;
            while(j < m && (x== 0 || !(a[i][j-1]=='1' && a[i][j]=='1'))){
                ++x;
                ++j;
            }
            if(x!=0)--j;
            cnt[i][0] += (x/2);
        }
    }

    int mini = 0, maxi = 0;

    rp(i,0,n){
        int one1 = cnt[i][2], one2 = cnt[i][2];
        int used1 = min(cnt[i][1], m/4);
        mini += used1;one1 -= (used1*2);
        mini += one1;
        int twos = m/4;
        twos -= min(twos,cnt[i][0]);
        one2 -= twos;
        maxi += one2;
    }

    cout << mini << " " << maxi << "\n";

    return 0;}