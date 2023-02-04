#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

bool check(int &n, int arr[], int k, int &c, int &d){
    int ans = 0;
    int to_add = d/(k+1),extra = d%(k+1);

    for(int i = 0; i < n && i < (k+1); i++){
        ans+=(to_add*arr[i]);
        if(extra>0){
            extra--;
            ans+=arr[i];
        }
    }

    return ans>=c;

}

int solve(int &n, int arr[],int &c,int &d){
    int low = 0,high = d;
    while(high-low>1){
        int mid = (low+high)/2;
        if(check(n,arr,mid,c,d)){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    if(check(n,arr,high,c,d))return high;
    return low;
    // return low;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,c,d;
        cin >> n >> c >> d;

        int arr[n],sum=0;
        rp(i,0,n){
            cin >> arr[i];
        }

        sort(arr,arr+n);
        reverse(arr,arr+n);

        for(int i = 0; i < d && i < n; i++){
            sum+=arr[i];
            // cout << arr[i] << " ";
        }

        if(sum>=c){
            cout << "Infinity\n";
            continue;
        }

        if(arr[0]*d<c){
            cout << "Impossible\n";
            continue;
        }

        cout << solve(n,arr,c,d) << "\n";

    }

    return 0;}