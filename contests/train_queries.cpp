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
        map<ll,deque<ll>> hsh;
        
        int a,n,m;
        cin >> n >> m;

        for(int i = 1;i <= n;i++){
            cin >> a;
            hsh[a].push_back(i);
        }

        while(m--){
            int x,y;
            cin >> x >> y;

            if(hsh.count(x) && hsh.count(y) && hsh[x][0]<=hsh[y][hsh[y].size()-1])cout<<"YES\n";
            else cout<<"NO\n";
        }
    }    

    return 0;}