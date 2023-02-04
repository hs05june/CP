#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n];

        for(int i = 0; i < n; i++)cin >> arr[i];

        int maxi[n+2]={0},mini[n+2];
        mini[n+1] = INT_MAX;
        
        for(int i = 1; i<=n; i++){
            maxi[i] = max(maxi[i-1],arr[i-1]);
        }

        for(int i = n; i>=1;i--){
            mini[i] = min(arr[i-1],mini[i+1]);
        }
        
        ll ans = 0;

        for(int i = 1; i <= n; i++){
            if(maxi[i]!=maxi[i+1] && maxi[i]<mini[i+1])ans++;
        }

        cout << ans << "\n";

    }

    return 0;}