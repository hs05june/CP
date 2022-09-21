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

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(n==1){cout << -1 ;return 0;}

    int start,end;

    if(n&1){
        start = ((n-1)/2)-1;
        end = (n+1)/2;
    }
    else{
        end = n/2;
        start = end-1;
    }
    
    int ans = abs(arr[end]-arr[start]);

    // cout << arr[start] << " " << arr[end] << " " << ans;

    while(start>=0 && end<n){
        ans = __gcd(ans,abs(arr[end]-arr[start]));
        start--;
        end++;
    }

    ans == 0 ? cout << -1 : cout << ans;

    return 0;}