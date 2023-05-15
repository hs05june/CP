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

    int n;
    cin >> n;

    set<int> nums;

    rp(i,1,n+1)nums.insert(i);

    int x = 1;
    while(!nums.empty()){
        if(sz(nums)==1){
            cout << *(nums.begin()) << " ";
            nums.clear();
            break;
        }
        deq num;
        for(auto i : nums){
            num.pb(i);
        }
        bool check = false;
        for(int i = x; i < sz(num); i+=2){
            if(i==sz(num)-1){
                check = true;
            }
            cout << num[i] << " ";
            nums.erase(num[i]);
        }
        if(check){
            x = 1;
        }
        else if(!check){
            x = 0;
        }
    }

    return 0;}