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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        if(n==0){
            return m%2==1 ? nums2[m/2] : (double)(nums2[m/2]+nums2[m/2-1])/(double)2;
        }
        if(m==0){
            return n%2==1 ? nums1[n/2] : (double)(nums1[n/2]+nums1[n/2-1])/(double)2;
        }
        
        int low = 0, high = n;
        int left = (n+m)%2==0 ? (n+m)/2 : (n+m)/2+1;
        int ans = 0;
        while(high-low>1){
            int mid = (low+high)/2;
            cout << mid << "\n";
            int al,ar;
            int right = left-mid;

            if(mid+m<left){
                low = mid+1;
                continue;
            }

            int bl, br;

            if(mid==0){
                al = -1000009;
                ar = nums1[mid];
            }
            else if(mid==n){
                al = nums1[mid-1];
                ar = 1000009;
            }
            else{
                al = nums1[mid-1];
                ar = nums1[mid];
            }
            if(right==0){
                bl = -1000009;
                br = nums2[right];
            }
            else if(right==m){
                bl = nums2[right-1];
                br = 1000009;
            }
            else{
                br = nums2[right];
                bl = nums2[right-1];
            }

            if(al>br){
                high = mid-1;
            }
            else{
                low = mid;
            }
        }



            int al,ar,bl,br;
            int right = left-low;
            if(low==0){
                al = -1000009;
                ar = nums1[low];
            }
            else if(low==n){
                al = nums1[low-1];
                ar = 1000009;
            }
            else{
                al = nums1[low-1];
                ar = nums1[low];
            }
            if(right==0){
                bl = -1000009;
                br = nums2[right];
            }
            else if(right==m){
                bl = nums2[right-1];
                br = 1000009;
            }
            else{
                br = nums2[right];
                bl = nums2[right-1];
            }
            // cout << low << " " << high << " " << ans << "\n";
        if(al<=br && bl<=ar){    
        return (n+m)%2==1 ? max(al,bl) : (double)(max(al,bl)+min(ar,br))/(double)2;}

        right = left-high;
            if(high==0){
                al = -1000009;
                ar = nums1[high];
            }
            else if(high==n){
                al = nums1[high-1];
                ar = 1000009;
            }
            else{
                al = nums1[high-1];
                ar = nums1[high];
            }
            if(right==0){
                bl = -1000009;
                br = nums2[right];
            }
            else if(right==m){
                bl = nums2[right-1];
                br = 1000009;
            }
            else{
                br = nums2[right];
                bl = nums2[right-1];
            }
        return (n+m)%2==1 ? max(al,bl) : (double)(max(al,bl)+min(ar,br))/(double)2;
        // return ans;
    }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;
        vector<int> nums1,nums2;
        rp(i,0,n){
            int x;
            cin >> x;
            nums1.pb(x);
        }

        rp(i,0,m){
            int x;
            cin >> x;
            nums2.pb(x);
        }

        cout << findMedianSortedArrays(nums1,nums2) << "\n";

    }

    return 0;}