#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

deq squares;
int ans[100007];

void fill_squares(){
    int n = 0;
    while(n*n<=300007){
        squares.push_back((n*n));
        ++n;
    }
}

void solve(int index){
    if(index<0)return;
    
    int x = *(lower_bound(all(squares),index));
    for(int i = index; i>=(x-index);i--){
        ans[i] = x-i;
    }
    solve(x-index-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill_squares();
    
    int t;
    cin >> t;

    while(t--){

    int n;
    cin >> n;
    
    solve(n-1);

    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

    return 0;}