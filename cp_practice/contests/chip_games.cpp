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
        ll n,m;
        cin >> n >> m;

        int ans = 0;
        if((n-1)&1)ans++;
        else ans+=2;

        if((m-1)&1)ans++;
        else ans+=2;

        if((ans%2)!=0)cout<<"Burenka\n";
        else cout<<"Tonya\n";

    }

    return 0;}