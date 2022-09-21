#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n,x,ans = 0;
        cin >> n >> x;
        int a[n];

        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        int mini = a[0]-x,maxi = a[0]+x;

        for(int i = 1; i < n; i++){
            int y = a[i] -x, z = a[i]+x;

            if(mini>z || maxi<y){
                ans++;
                mini = y;
                maxi = z;
            }
            else{
                mini = max(y,mini);
                maxi = min(z,maxi);
            }
        }
        cout << ans << "\n";
    }

    return 0;}