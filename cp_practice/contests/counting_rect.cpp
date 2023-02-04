#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

ll arr[1007][1007];
ll preffix[1007][1007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        memset(arr, 0, sizeof(arr));
        memset(preffix, 0, sizeof(preffix));

    int n,q;
    cin >> n >> q;

    int h,w,hmax=0,wmax=0;

    for(int i = 0; i < n; i++){
        cin >> h >> w;
        arr[h][w]+= (h*w);
        hmax = max(hmax,h);
        wmax = max(wmax,w);
    }

    for(int i = 1; i <= 1005; i++){
        for(int j = 1; j <= 1005 ; j++){
            preffix[i][j] = preffix[i-1][j] + preffix[i][j-1] + arr[i][j] - preffix[i-1][j-1];
        }
    }
    while(q--){
        int hs,ws,hb,wb;
        cin >> hs >> ws >> hb >> wb;

        cout << (preffix[hb-1][wb-1] - preffix[hb-1][ws] - preffix[hs][wb-1] + preffix[hs][ws])<<"\n";
    }
}
    return 0;}