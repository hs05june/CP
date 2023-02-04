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

    string a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int cnt[2] = {0};
    bool together = false;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cnt[a[i][j]-'0']++;

            if((j+1)<m && a[i][j]=='0' && a[i][j+1]=='0'){
                together = true;
            }
            if((i+1)<n && a[i][j]=='0' && a[i+1][j]=='0'){
                together = true;
            }
            if((i+1)<n && (j+1)<m && a[i][j]=='0' && a[i+1][j+1]=='0'){
                together = true;
            }
            if((i+1)<n && (j-1)>=0 && a[i][j]=='0' && a[i+1][j-1]=='0'){
                together = true;
            }
        }
    }

    if(cnt[0]==0){
        cout << (cnt[1]-2)<<"\n";
    }
    else if(!together){
        cout << (cnt[1]-1)<<"\n";
    }
    else if(together){
        cout << (cnt[1])<<"\n";
    }
}
    return 0;}