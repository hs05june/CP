#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[4] = {1,2,3,4};
    int b[4];

    copy_n(b,4,a);

    for(int i = 0; i < 4; i++){
        cout << b[i] << " ";
    }

    return 0;}