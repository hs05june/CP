#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
using namespace std;

signed main(){

    int test;
    cin >> test;

    while(test--){

        string arr;
        cin >> arr;

        set<char> palindrome;
        rp(i,0,(arr.size()/2)){
            palindrome.insert(arr[i]);
        }
        if(palindrome.size()>1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;}