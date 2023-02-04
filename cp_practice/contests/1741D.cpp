//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
const ll M = 1000000007;
using namespace std;

int arr[262150];
int mini[1048600];
int maxi[1048600];
int ans;

void solve(int left, int right){
    if(left==right)return;

    // rep(i,left,right)cout << arr[i] << " ";
    // cout << "\n";
    int mid = (left+right)/2;
    int ml = *max_element(arr+left,arr+mid+1);
    int mr = *max_element(arr+mid+1,arr+right+1);

    // cout << ml << " " << mr << "\n";
    if(ml>mr){
        ++ans;
        for(int i = left; i <= mid; i++){
            swap(arr[i],arr[i+mid-left+1]);
        }
    }
    solve(left,mid);
    solve(mid+1,right);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        ans = 0;
        int n;
        cin >> n;

        for(int i = 0;i <=n; i++)arr[i] = 0;
        for(int i = 1;i <=4*n; i++){mini[i] = 0;maxi[i] = 0;}

        rp(i,0,n)cin >> arr[i];

        solve(0,n-1);

        bool possible = true;

        for(int i = 0; i<n-1;i++){
            if(arr[i]>arr[i+1]){
                possible = false;
                break;
            }
        }

        // rp(i,0,n)cout << arr[i] << " ";
        if(!possible){
            cout << "-1\n";
            continue;
        }

        cout << ans << "\n";

    }

    return 0;}