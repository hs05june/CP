#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
ull n;
using namespace std;

bool check(ull mid){
    return mid*(mid+1)<=2*(n+1);
}

ull solve(ull low,ull high){

    while(high-low>1){
        ull mid = (low+high)/2;
        if(check(mid)){
            low =mid;
        }
        else{
            high = mid-1;
        }
    }

    if(check(high))return high;
    return low;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    cin >> n;

    ull x = 2*(sqrt(n+1)+1);

    ull ans = solve(1,x);

    cout << (n-ans+1) << "\n";
}
    return 0;
    }