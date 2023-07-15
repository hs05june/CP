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

int arr[3007];

bool check(int mid, int k, int n, int maxi){
    rp(i, 0, maxi-mid+1){
        bool check = true;
        rp(j, 0, n){
            int value;
            if(i > arr[j]){
                check = false;
                break;
            }
            if(arr[j] >= i && arr[j] <= (i+mid))continue;
            if((i+mid) == 0)value = arr[j]+1;
            else{
                int x = arr[j] / (i+mid);
                value = (x == 0 || (arr[j] / x) > (i+mid)) ? x+1 : x;
            }
            if(!(arr[j] / value >= i && arr[j] / value <= (i+mid) && k >= value) && !(arr[j] / k >= i && arr[j] / k <= (i+mid))){
                check = false;
                break;
            }
        }
        if(check)return true;
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        int maxi = 0, mini = 3007;

        rp(i,0,n){
            cin >> arr[i];
            maxi = max(maxi,arr[i]);
            mini = min(mini,arr[i]);
        }

        int low = 0, high = abs(maxi - mini);

        while(high - low > 1){
            int mid = (low + high)/2;
            if(check(mid,k,n,maxi)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        if(check(low,k,n,maxi))cout << low << "\n";
        else cout << high << "\n";

    }

    return 0;}