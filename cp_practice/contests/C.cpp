#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
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
        int c = n;
        int x = 9;
        int y = 1;
        int num = 0;
        while(c>0){
            if(c<x){num+=(c*y);c-=c;y*=10;}
            else{num += (x*y);
            c-=x;
                x--;y*=10;
            }
        }
        cout<<num<<"\n";
    }

    return 0;}