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

    int n;
    cin>>n;
    int a[n];
    int fall[n];
    int fallb[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i>=1){
            fall[i] = (a[i]<a[i-1]) ? (a[i-1]-a[i]):0;
        }
    }

    int pref[n+1]={0};
    int z = 0;
    pref[0]=0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1]+fall[i-1];
    }

    for(int i = 0; i < n; i++){
        cout << fall[i]<<" ";
    }
    cout << "\n";

    for(int i = 1; i <= n; i++){
    cout << pref[i]<<" ";
    }

    return 0;}