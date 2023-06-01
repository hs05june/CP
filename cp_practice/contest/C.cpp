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

int n,k;
int arr[200007];

bool check(int mid){
    int filled = 0, left = mid;
    rp(i,1,n+1){
        if(arr[i]>=mid){
            filled++;
        }
        else if(arr[i]==left){
            filled++;
            left = mid;
        }
        else if(arr[i]>left){
            filled++;
            int z = arr[i] - left;
            left = mid - z;
        }
        else if(arr[i]<left)left-=arr[i];
    }
    // cout << mid << " " << filled << "\n";
    return (filled>=k);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        cin >> n >> k;
        arr[0] = 0;

        int sum = 0;
        
        rp(i,1,n+1){cin >> arr[i];sum+=arr[i];}

        int low = 0, high = (sum/k);

        while((high-low)>1){
            int mid = (low+high)/2;
            if(check(mid))low = mid;
            else high = mid-1;
        }

        if(check(high))cout << high << "\n";
        else cout << low << "\n";

    }

    return 0;}