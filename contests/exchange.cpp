#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

void print_all(int arr[],int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){

    int n;
    cin >> n;
    
    int x = n;

    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = i+1;
    }
    cout<<n<<"\n";
    print_all(arr,n);
    swap(arr[0],arr[n-1]);
    x-=2;

    print_all(arr,n);

    while(x--){
        swap(arr[x+2],arr[x+1]);
        print_all(arr,n);
    }

    }
    return 0;}