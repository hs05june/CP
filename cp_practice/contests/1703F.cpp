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

    ll n;
    cin >> n;

    ll arr[n+1]={0};
    deque<ll> pairs,indices;
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
        if(arr[i]<i){
            pairs.push_back(arr[i]);
            indices.push_back(i);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < pairs.size(); i++){
        ll z = lower_bound(indices.begin(),indices.end(),pairs[i])-indices.begin();
        ans+=z;
    }
    cout << ans << "\n";
    }   

    return 0;}