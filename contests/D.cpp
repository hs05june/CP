#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

string text;
int colored[100] = {0};
deque<string> arr;

bool check(int n){
    bool x = true;
    for(int i = 0; i < n; i++){
        if(colored[i] ==0){
            x = false;
            break;
        }
    }
    return x;
}

bool to_use(int x,int y){
    bool used = false;

    for(int i = x; i <= y; i++){
        if(colored[i] == 0){
            used=true;
            break;
        }
    }
    return x;
}

void color(int x,int y){
    for(int i = x; i <= y; i++){
        colored[i] = 1;
    }
}

void array_update(int a[],int b[],int n){
    for(int i = 0; i < n; i++){
        a[i] = b[i];
    }
}

int solve(){
    if(check(text.size())){
        return 0;
    }
    int n = text.size();
    int colore[n];
    array_update(colore,colored,n);
    int ans = INT_MAX;
    bool used = false;
    for(int i = 0; i < arr.size(); i++){
        int z = text.find(arr[i]);
        int s = arr[i].size();
        bool carry = true;

        while(z!=string::npos && carry){if(to_use(z,z+s-1)){
            color(z,z+s-1);
            used = true;
            carry = false;
            ans = min(ans,1+solve());
            array_update(colored,colore,n);
        }else{
            z = text.find(arr[i],z+1);
        }}
        
    }
    return used ? ans : M;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

 
       
        cin >> text;
        int n;
        cin >> n;
        
       
       for(int i = 0; i < n; i++){
        string y;
        cin >> y;
        arr.push_back(y);
       }
        cout << solve();

    return 0;}