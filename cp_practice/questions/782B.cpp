#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
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
const ld M = 0.00000001;
using namespace std;

ld arr[60007], speed[60007];

bool check(ld mid, int n){
    ld mini = LLONG_MIN, maxi = LLONG_MAX;
    rp(i,0,n){
        mini = max(mini,arr[i]-mid*speed[i]);
        maxi = min(maxi,arr[i]+mid*speed[i]);
    }
    return mini <= maxi;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    ld mini = 10000000000, maxi = 0;

    rp(i,0,n){
        cin >> arr[i];
        mini = min(mini,arr[i]);
        maxi = max(maxi,arr[i]);
    }
    rp(i,0,n)cin >> speed[i];

    ld low = 0, high = abs(maxi-mini);

    while(high - low > M){
        ld mid = (low + high) / 2;
        if(check(mid,n)){
            high = mid;
        }
        else{
            low = mid+M;
        }
    }

    if(check(low,n))cout << low << "\n";
    else cout << high << "\n";

    return 0;}