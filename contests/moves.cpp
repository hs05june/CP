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
        ull n;
        cin >> n;

        ull ans = 0;

        if(n==1){
            ans=2;
        }
        else if((n%3)==0){
            ans += (n/3);
        }

        else if((n%3)==2){
            ans+=(n/3);
            ans++;
        }

        else if((n%3)==1){
            ans+=((n/3)-1);
            ans+=2;
        }

        cout<<ans<<"\n";

    }

    return 0;}