#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define int long long
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

signed main(){
    CODE BY HARPREET

        int n;
        cin >> n;

        if(n==1)cout<<"3\n";
        else if(n==2)cout<<"5\n";
        else if(n==3)cout<<"7\n";
        else{
            n-=3;
            if(n%3==1){
                cout << 4*((n/3)+2)<<"\n";
            }
            else if(n%3==2){
                cout << (4*((n/3)+2))+1<<"\n";
            }
            else if(n%3==0){
                cout << (4*((n/3)+2))-1<<"\n";
            }
        }

    return 0;}