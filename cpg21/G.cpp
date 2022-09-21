#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 998244353;
using namespace std;

ll arr[20];
ll dp[20][20];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;

    cin >> n >> k;

    for(int i = 1; i <=k; i++){
        cin >> arr[i];
    }

    return 0;}