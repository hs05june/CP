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
        int n,m;
        cin >> n >> m;

        int arr[n+1]={0},presence[n+1]={0};
        pii pairs[m];

        for(int i=1;i<n+1;i++){
            cin >> arr[i];
        }

        for(int i=1;i<m+1;i++){
            int x,y;
            cin >> x >> y;
            pairs[i-1]={x,y}; 
            presence[x]++;
            presence[y]++;
        }

        if(!(m&1)){
            cout<<"0\n";
            continue;
        }

        int ans = INT_MAX;

        for(int i=1;i<n+1;i++){
            if(presence[i]&1){
                ans = min(ans, arr[i]);
            }
        }

        for(int i=0;i<m;i++){
            if(presence[pairs[i].first]%2==0 && presence[pairs[i].second]%2==0){
                ans = min(ans, arr[pairs[i].first]+arr[pairs[i].second]);
            }
        }
        cout<<ans<<"\n";
    }

    return 0;}