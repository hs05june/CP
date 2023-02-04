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

    string a;
    cin >> a;

    int n = a.length();

    ull ans = 0;

    for(int i = 0; i<n; i++){
        if(a[i]=='1'){
            ull x = (min(i,n-i-1) + 1);
            ull z = (x*(x-1)/2) + (x*(x+1)/2) + ((n-(2*x)+1)*x);
            ans += z;
        }
    }

    cout << ans << "\n";

    return 0;}