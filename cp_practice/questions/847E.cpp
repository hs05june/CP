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
const ll M = 1000000007;
using namespace std;

bool check(ll mid, string a){
    queue<int> ast, pac;
    rp(i,0,sz(a)){
        if(a[i]=='*'){
            ast.push(i);
        }   
        if(a[i]=='P'){
            pac.push(i);
        }
    }
    while(!pac.empty() && !ast.empty()){
        int x = pac.front();
        if(ast.front() < x){
            if(x - ast.front() > mid)return false;
            int y = ast.front();
            while(!ast.empty() && ast.front() < x)ast.pop();
            int z = (x-y);
            while(!ast.empty() && ((ast.front() - x + 2*z) <= mid || (2*(ast.front()-x)+z) <= mid))ast.pop();
        }
        else{
            while(!ast.empty() && abs(ast.front() - x) <= mid)ast.pop();
        }
        pac.pop();
    }
    return ast.empty();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    cin >> n;

    string a;
    cin >> a;

    ll low = 0, high = 2*n;

    while(high - low > 1){
        ll mid = (low + high) / 2;
        if(check(mid,a)){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }

    if(check(low,a)){
        cout << low << "\n";
    }
    else{
        cout << high << "\n";
    }


    return 0;}