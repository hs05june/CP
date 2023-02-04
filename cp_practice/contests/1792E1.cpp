#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
#define int long long
int M = 1000000007;
using namespace std;


signed main(){
    CODE BY HARPREET

    ll i = 2;
    while(true){
        int x,y;
        cout << "? 1 " << i << endl;
        cin >> x;
        if(x==-1){
            cout <<"! " << i-1 << endl;
            break;
        }
        cout << "? " << i << " 1" << endl;
        cin >> y;
        if(y==-1){
            cout <<"! " << i-1 << endl;
            break;
        }

        if(x!=y){
            cout <<"! " << x + y << endl;
            break;
        }
        ++i;
    }

    return 0;}