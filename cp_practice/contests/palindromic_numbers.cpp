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

   string a;
   cin >> a;
   string x;
   if(a[0]!='9'){
    for(int i = 0; i < n; i++){
        x.push_back(char('9'-a[i]+'0'));
    }
   }
   else{
    for(int i = 0; i < n-1; i++){
        x.push_back(char(10+'0'-a[i]));
    }
    x.push_back(char());
   }
   cout<<x<<"\n";
   }

    return 0;}