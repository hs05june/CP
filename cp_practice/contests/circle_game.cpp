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

        int a[n];
        cin >> a[0];
        int x = a[0],k = 0;
        for(int i = 1; i < n; i++){
            cin >> a[i];
            if(x>a[i]){
                x = a[i];
                k =i;
            }
        }

        if(n&1)cout<<"Mike\n";
        else{
            ((k+1)&1) ? cout << "Joe\n": cout<<"Mike\n";
        }
    }

    return 0;}