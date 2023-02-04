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

    int q;
    cin >> q;

    while(q--){
        int x,y,l,r;
        cin >> x >> y >> l >> r;

        deq dp(r+1);

        dp[0] = x,dp[1]=y;

        int sum = 0;

        for(int i = 2; i <= r; i++){
            if(i&1)dp[i] = dp[i-1]^dp[i-2];
            else dp[i] = dp[i-1]|dp[i-2];
            if(i>=l && i<=r)sum+=dp[i];
        }

        cout << sum << "\n";
    }

    return 0;}