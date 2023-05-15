#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define int long long
using namespace std;

signed main(){

    int t;
    cin >> t;

    while(t--){

        int n,num;
        cin >> n >> num;

        int array[n];
        int total = 0;

        rp(i,0,n){
            cin >> array[i];
            total+=array[i];
        }

        int total1 = 0;
        
        sort(array,array+n);

        rp(i,0,2*num)total1+=array[i];
        int total2 = total1;
        int j = n-1;
        for(int i = 2*num-1; i>=0; i-=2){
            total1 += (array[j]-array[i]-array[i-1]);
            --j;
            total2 = min(total2,total1);
        }
        cout << total - total2 << "\n";
    }
    return 0;}