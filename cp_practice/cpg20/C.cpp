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

    int a[n];

    float total = 0,p[n];

    for(int i = 0; i< n; i++){
        cin >> p[i];
    }

    for(int i = 0; i< n; i++){
        cin >> a[i];
        if(a[i] >= m)total+=p[i];
    }

    for(int i = 0; i< n; i++){
        if(a[i]<m)cout << setprecision(10)<<0<<" ";
        if(a[i]>=m)cout << setprecision(10) << (p[i]/total)<<" ";
    }

    return 0;}