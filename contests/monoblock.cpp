#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

ll a[100007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin >> n >> m;
    ull ans = n*(n+1)/2;
    
    for(int i = 1; i<=n;i++){
        cin >> a[i];
    }

    for(int i = 1; i<=n; i++){
        if(a[i]!=a[i+1]){
            ans += (i)*(n-i);
        }
    }

    // cout << ans << "\n";

    while(m--){
        ll x,y;
        cin >> x >> y;

        if( (x+1)<=n && a[x]==a[x+1] && a[x+1]!=y){
            ans+=x*(n-x);
        }

        if((x-1)>=0 && a[x-1]==a[x] && a[x-1]!=y){
            ans += (x-1)*(n-x+1);
        }

        if((x+1)<=n && a[x]!=a[x+1] && a[x+1]==y){
            ans -= (x)*(n-x);
        } 
        if((x-1)>=0 && a[x]!=a[x-1] && a[x-1]==y){
            ans -= (x-1)*(n-x+1);
        } 

        a[x] = y;

        cout << ans << "\n";
    }

    return 0;}