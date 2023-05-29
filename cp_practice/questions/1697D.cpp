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
    // cin >> t;

    while(t--){

        int n;
        cin >> n;

        string a = "";

        deq uniq;

        rp(i,1,n+1){
            bool check = true;
            if(sz(uniq)!=0){
                int low = 0, high = sz(uniq)-1;
                while(high -low > 1){
                    int mid = (low+high)/2;
                    cout << "? 2 " << uniq[mid] << " " << i << endl;
                    int y;
                    cin >> y;
                    if(y < sz(uniq)-mid+1){
                        low = mid;
                    }
                    else{
                        high = mid - 1;
                    }
                }
                cout << "? 2 " << uniq[high] << " " << i << endl;
                int y;
                cin >> y;
                if(y < sz(uniq)-high+1){
                    check = false;
                    a.pb(a[uniq[high]-1]);
                    uniq[high] = i;
                    sort(all(uniq));
                    continue;
                }
                cout << "? 2 " << uniq[low] << " " << i << endl;
                cin >> y;
                if(y < sz(uniq)-low+1){
                    check = false;
                    a.pb(a[uniq[low]-1]);
                    uniq[low] = i;
                    sort(all(uniq));
                }
            }
            if(check){
                cout << "? 1 " << i << endl;
                uniq.pb(i);
                sort(all(uniq));
                char y;
                cin >> y;
                a.pb(y);
            }
        }
        cout << "! " << a << endl;
    }

    return 0;}