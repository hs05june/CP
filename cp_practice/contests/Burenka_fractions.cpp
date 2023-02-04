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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if((a*d)==(c*b)){
            cout << "0\n";
            continue;
        }

        ll x = a*d,y = b*c;

        if(x<y)swap(x,y);

        if(x==0 || y==0 || (x%y)==0)cout<<"1\n";
        else cout << "2\n";

    }

    return 0;}