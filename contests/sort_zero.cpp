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
        set<int> dis;
        int n;
        cin >> n;
        int num_distinct[n+1] = {0}; 
        int arr[n+1] = {0};

        for(int i = 1; i<=n; i++){
            cin >> arr[i];
            if(!dis.count(arr[i])){
                num_distinct[i] = 1 + num_distinct[i-1];
                dis.insert(arr[i]);
            }
            else{
                num_distinct[i] = num_distinct[i-1];
            }
        }
        
    }

    return 0;}