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
    int n,l,r;
    cin >> n >> l >> r;

    int arr[n+1];
    arr[0] = 0;

    bool ans = true;

    for(int i = 1; i <= n; i++){
        if(l%i==0){
            arr[i] = l;
        }
        else if((l +i - (l%i))<=r){
            arr[i] = l +i - (l%i);
        }
        else if((l+i-(l%i))>r){
            ans = false;
            break;
        }
    }

    if(ans==false){
        cout<<"NO\n";
        continue;
    }
    cout<<"YES\n";
    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n";}

    return 0;}