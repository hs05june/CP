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

    string a;
    cin >> a;

    int n = a.length();

    int index = 0;
    char x = a[0];

    for(int i = 0; i<(n-1);i++){
        if(x > a[i]){
            index = i;
            x = a[i];
        }
    }

    char y = a[index+1];

    for(int i = index+1; i < n; i++){
        if(y>a[i]){
            y=a[i];
        }
    }

    cout << x << y << "\n";

    return 0;}