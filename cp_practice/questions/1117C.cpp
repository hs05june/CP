#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define int long long
#define ll long long
#define ld long double
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

// 0 -> U, 1 -> D, 2 -> R, 3 -> L
map<char,int> m;
int cnt[100007][4];
int need[4];

bool check(ll mid, int n){
    ll avail[4];
    rp(i,0,4)avail[i] = 0;
    
    int x = mid / n;
    
    rp(i,0,4){
        avail[i] = x*cnt[n][i];
    }
    
    int y = mid%n;
    rp(i,0,4){
        avail[i] += cnt[y][i];
    }

    int use = 0, req = 0;

    ll z1 = min(avail[0],avail[1]);
    use+=(2*z1);avail[0]-=z1;avail[1]-=z1;

    ll z2 = min(avail[2],avail[3]);
    use+=(2*z2);avail[2]-=z2;avail[3]-=z2;
    
    rp(i,0,4){
        use += min(avail[i],need[i]);
        req += max(0LL,need[i]-avail[i]);
    }

    return req <= use;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n;
    cin >> n;

    if(x2>=x1)need[2] = x2-x1;
    if(x2<x1)need[3] = x1-x2;
    if(y2 >= y1)need[0] = y2-y1;
    if(y2<y1)need[1] = y1-y2;

    string a;
    cin >> a;

    m['U'] = 0;
    m['D'] = 1;
    m['R'] = 2;
    m['L'] = 3;

    rp(i,0,n){
        rp(j,0,4)cnt[i+1][j] = cnt[i][j];
        cnt[i+1][m[a[i]]]++;
    }

    int low = 0, high = LLONG_MAX/2;

    while(high - low > 1){
        int mid = (high + low) / 2;
        if(check(mid,n)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }

    if(check(low,n)){
        cout << low << "\n";
    }

    else if(check(high,n)){
        cout << high << "\n";
    }
    else{
        cout << "-1\n";
    }

    return 0;}