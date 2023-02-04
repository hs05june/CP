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

    int n,m;
    cin >> n >> m;

    bool present =false;
    int great = 0;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i]==m)present = true;
        if(arr[i]>m)great++;
    }

    if(present)cout << great << endl;
    else cout << -1 << endl;

    return 0;}