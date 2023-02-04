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
    int n,m;
    cin >> n >> m;

    deq infected;

    for(int i = 0; i<m; i++){
        int k;
        cin >> k;
        infected.push_back(k);
    }    

    sort(all(infected));
    deq uninfected;

    if(m == 1){
        int can_be = n-m;
        (can_be <= 1) ? cout<<n-can_be<<"\n" : cout << n-can_be+1<<"\n";
        continue;
    }

    for(int i = 1; i<m; i++){
        int k = infected[i]-infected[i-1]-1;
        uninfected.push_back(k);
    }

    uninfected.push_back(n-infected[m-1]+infected[0]-1);

    sort(all(uninfected));
    reverse(all(uninfected));

    int z = 0,ans = 0;

    // for(int i = 0; i<uninfected.size(); i++){
    //     cout<<uninfected[i]<<" ";
    // }

    for(int i = 0; i<uninfected.size(); i++) {
        if((uninfected[i]-z)<=0)break;
        if((uninfected[i]-z)<=2){ans++;z+=2;}
        else{
            ans+=(uninfected[i]-z-1);
            z+=4;
        }
    }

    cout<<n-ans<<"\n";}


    return 0;}