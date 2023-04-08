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
    cin >> t;

    while(t--){

        int n,q,l,r;
        cin >> n >> q;

        int arr[n+1] = {0};
        rp(i,1,n+1)cin >> arr[i];

        cin >> l >> r;

        int preffix_sum[n+1] = {0}, preffix_xor[n+1] = {0};
        preffix_sum[0] = preffix_xor[0] = 0;

        rp(i,1,n+1){
            preffix_sum[i] = preffix_sum[i-1] + arr[i];
            preffix_xor[i] = preffix_xor[i-1] ^ arr[i];
        }

        int ans = (preffix_sum[r]-preffix_sum[l-1]) - (preffix_xor[l-1] ^ preffix_xor[r]);
        int left = 1, right = r, diff = r;

        rp(i,l,r+1){
            int low = i,high = r;
            if(((preffix_sum[r] - preffix_sum[i-1]) - (preffix_xor[i-1] ^ preffix_xor[r])) == ans){
                while(high-low>1){
                    int mid = (low+high)/2;
                    if(((preffix_sum[mid] - preffix_sum[i-1]) - (preffix_xor[i-1] ^ preffix_xor[mid])) == ans){
                        high = mid;
                    }
                    else {
                        low = mid+1;
                    }
                }
                if(((preffix_sum[low] - preffix_sum[i-1]) - (preffix_xor[i-1] ^ preffix_xor[low])) == ans){
                    if((low - i + 1) < diff){
                        right = low;
                        left = i;
                        diff = (low - i + 1);
                    }
                }   
                else{
                    if(high - i + 1 < diff){
                        right = high;
                        left = i;
                        diff = (high - i + 1);
                    }
                }
            }
        }

        cout << left << " " << right << "\n";

    }

    return 0;}