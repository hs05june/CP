#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll unsigned long long
#define int unsigned long long
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
    cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;
        int m = n;
        int arr[n];
        rp(i,0,n)cin >> arr[i];

        sort(arr,arr+n);

        int index = n-1;

        rp(i,0,n-1){
            int z = arr[i+1] - arr[i];
            int req = z*(i+1);
            if(k>=req){
                k-=req;
            }
            else{
                index = i;
                break;
            }
        }
        
        if(k>0){
            int x = k/(index+1), y = k%(index+1);
            arr[index]=(x%M + arr[index]%M)%M;
            rp(i,0,index)arr[i] = (arr[index]%M);
            rp(i,0,y)arr[i] = (arr[i]%M + 1%M)%M;
        }

        int ans = 0, sum = 0;

        rp(i,0,n){
            ans = (ans%M + (arr[i]%M * sum%M)%M)%M;
            sum = sum + arr[i];
        }
        cout << ans%M << "\n";
    }

    return 0;}