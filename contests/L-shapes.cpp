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

    while(t--){
        int n,m;
        bool visited[n][m] = {false};

        string a[n];

        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        bool check = true;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]=='*' && !visited[i][j]){
                
                if((i+1)<n && (j+1)<m && a[i+1][j]=='*' && !visited[i+1][j] && a[i+1][j+1]=='*' && !visited[i+1][j+1]){
                    visited[i][j] = true;
                    visited[i+1][j+1] = true;
                    visited[i+1][j] = true;
                    if(((i-1)>=0 && a[i-1][j]=='*') || ((j-1)>=0 && a[i][j-1]=='*') || ((i-1)>=0 && (j-1)>=0 && a[i-1][j-1]=='*') || ((i-1)>=0 && (j+1)<m && a[i-1][j+!]=='*') || ((j+1)<m && a[i][j+1]=='*') || ((j+2)<m && a[i][j+2]=='*') || ((i+1)<n && (j-1)>=0 && a[i+1][j-1]=='*') || ((i+2)<n && (j-1)>=0 && a[i+2][j-1]=='*') || ((i+1)<n && (j+2)<m && a[i+1][j+2]=='*') || ((i+2)<n && (j+2)<m && a[i+2][j+2]=='*') || ((i+2)<n && (j+1)<m && a[i+2][j+1]=='*') || (i+2)<n && a[i+2][j]=='*'){
                        check = false;
                        break;
                    }
                }
                if((i+1)<n && (j-1)>=0 && a[i+1][j]=='*' && !visited[i+1][j] && a[i+1][j-1]=='*' && !visited[i+1][j-1]){
                    visited[i][j] = true;
                    visited[i+1][j-1] = true;
                    visited[i+1][j] = true;
                    if(((i-1)>=0 && a[i-1][j]=='*') || ((j-1)>=0 && a[i][j-1]=='*') || ((i-1)>=0 && (j-1)>=0 && a[i-1][j-1]=='*') || ((i-1)>=0 && (j+1)<m && a[i-1][j+!]=='*') || ((j+1)<m && a[i][j+1]=='*') || ((j-2)>=0 && a[i][j-2]=='*') || ((i+1)<n && (j+1)<m && a[i+1][j+1]=='*') || ((i+2)<n && (j+1)<m && a[i+2][j+1]=='*') || ((i+1)<n && (j-2)>=0 && a[i+1][j-2]=='*') || ((i+2)<n && (j-2)>=0 && a[i+2][j-2]=='*') || ((i+2)<n && (j+1)<m && a[i+2][j+1]=='*') || (i+2)<n && a[i+2][j]=='*'){
                        check = false;
                        break;
                    }
                }
                
                }
                else{
                    check = false;
                    break;
                }
                }
            }
            if(!check)break;
        }
    }

    return 0;}