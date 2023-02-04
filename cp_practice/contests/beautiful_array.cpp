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
        ll n,k,b,s;
        cin >> n >> k >> b >>s;

        if(s<(k*b) || s > ((k*b)+n*(k-1))){
            cout << "-1\n";
            continue;
        }

        ll z = k*b;
        ll extra = s - z;
        ll ans[n] = {0};
        ans[0] = (k*b);

        for(int i = 0; i < n; i++){
            if(extra>=(k-1)){
            ans[i]+=(k-1);extra -= (k-1);}
            else{
                ans[i] += extra;
                extra = 0;
            }
        }

        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;}