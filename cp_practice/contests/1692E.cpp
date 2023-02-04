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

    int n,s;
    cin >> n >> s;

    deq index;
    int sum = 0;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        sum+=a;
        if(a==1)index.push_back(i);
    }

    if(sum<s){cout<<"-1\n";continue;}
    if(sum==s){cout<<"0\n";continue;}

    sort(all(index));
    

    mii forward,backward;
    forward[0] = 0;
    backward[0] = 0;
    for(int i=0; i<index.size(); i++){
        forward[i+1] = index[i];
        backward[i+1] = n-index[index.size()-1-i]+1;
    }
    
    int to_remove = sum - s;

    int ans = INT_MAX;

    for(int i=0; i<=to_remove; i++){
        ans = min(ans,forward[i]+backward[to_remove-i]);
    }
  
    cout<<ans<<"\n";}
    return 0;}