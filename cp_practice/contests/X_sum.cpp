#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

int n,m;
int arr[207][207];

int right_down[207][207];
int right_up[207][207];

void calculate_right_down(int x,int y){
    int i = x;
    int j = y;
    for(;i<=n&&j<=m;i++,j++){
        right_down[x][y]+=arr[i][j];
    }
}
void calculate_right_up(int x,int y){
    int i = x;
    int j = y;
    for(;i>0&&j<=m;i--,j++){
        right_up[x][y]+=arr[i][j];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        memset(right_down,0,sizeof(right_down));
        memset(right_up,0,sizeof(right_up));
        memset(arr,0,sizeof(arr));
        cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        calculate_right_down(i,1);
    }
    for(int i = 2; i <= m; i++){
        calculate_right_down(1,i);
    }
    for(int i = 1; i <= n; i++){
        calculate_right_up(i,1);
    }
    for(int i = 2; i <= m; i++){
        calculate_right_up(n,i);
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j<= m; j++){
            right_down[i][j] = right_down[i-1][j-1];
        }
    }
    
    for(int i = 2; i<= m; i++){
        for(int j = 1; j< n; j++){
            right_up[j][i] = right_up[j+1][i-1];
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ans = max(ans, right_up[i][j]+right_down[i][j] - arr[i][j]);
        }
    }

    cout<<ans<<"\n";}
   
    return 0;}