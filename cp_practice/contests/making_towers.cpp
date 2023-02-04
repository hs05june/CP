#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

deq arr[100007];

int solve(int x){
    int curr = arr[x][0];
    int ans = 1;

    for(int i : arr[x]){
        if((i&1)!=(curr&1)){
            ans++;
            curr=i;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
    int n;
    cin >> n;

    for(int i = 1; i<=n; i++){
        arr[i].clear();
    }
    
    int x;
    set<int> s;

    for(int i = 1; i <= n; i++){
        cin >> x;
        s.insert(x);
        arr[x].push_back(i);
    }    

    for(int i = 1; i <= n; i++){
        if(!s.count(i))cout<<"0 ";
        else{
            cout<<solve(i)<<" ";
        }
    }

    cout<<"\n";}

    return 0;}