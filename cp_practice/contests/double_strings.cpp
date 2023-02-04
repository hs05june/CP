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
    cin>>t;

    while(t--){int n;
    cin >> n;
    string arr[n];
    set<string> s;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }

    for(int i = 0; i < n; i++){
        bool check = false;
        for(int j =1;j < arr[i].size();j++){
            string x = arr[i].substr(0,j);
            string y = arr[i].substr(j);
            if(s.count(x)&&s.count(y)){
                check = true;
                break;
            }
        }
        if(check)cout<<1;
        else cout<<0;
    }
    
    cout<<"\n";}

    return 0;}