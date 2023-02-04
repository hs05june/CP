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
        int n;
        cin >> n;
        int start;
        if((n%2)==0){
            start = 1;
        }
        else{
            cout << "1 ";
            start = 2;
        }
        for(int i = start; i<=n;i+=2){
            cout << i+1<<" "<<i<<" ";
        }
        cout << "\n";
    }

    return 0;}