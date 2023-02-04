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
    int n,k;
    cin >> n >> k;

    if(k%4==0){
        cout << "No\n";
        continue;
    }

    if(k%2!=0){
        cout<<"Yes\n";
        for(int i = 1; i <= n; i+=2){
            cout<<i<<" "<<i+1<<'\n';
        }
    }

    if(k%4==2){
        cout << "Yes\n";
        for(int i = 1; i <= n; i+=4){
            cout << i+1 << " "<< i <<'\n';
        }
        for(int i = 3; i <= n; i+=4){
            cout << i << " " <<i+1<<'\n';
        }
    }
    }
    return 0;}