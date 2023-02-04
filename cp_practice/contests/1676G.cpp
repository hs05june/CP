// #include<bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define deq deque<int>
// #define mii map<int,int>
// #define pii pair<int,int>
// #define all(x) (x).begin(), (x).end()
// int M = 1000000007;
// using namespace std;

// int cnt[4007][2];
// // 0= whhite,1=black
// deq graph[4007];
// string a;

// pii solve(int n){
//     if(graph[n].empty()){
//         if(a[n-1]=='W')return {1,0};
//         if(a[n-1]=='B')return {0,1};
//     }
    
//     int w = 0,b=0;

//     for(auto i : graph[n]){
//         auto z = solve(i);
//         w+=z.first;
//         b+=z.second;
//     }

//     cnt[n][0]+=w;
//     cnt[n][1]+=b;

//     return {cnt[n][0],cnt[n][1]};
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;

//     while(t--){
    
//     for(int i = 0; i < 4007; i++){
//         graph[i].clear();
//         cnt[i][0] = 0;
//         cnt[i][1] = 0;
//     }
//     a = "";

//     int n;
//     cin >> n;

//     for(int i = 2; i <= n; i++){
//         int x;
//         cin >> x;
//         if(x!=i)graph[x].push_back(i);
//     }
    
//     cin >> a;

//     for(int i = 0; i < n; i++){
//         if(a[i]=='W')cnt[i+1][0]++;
//         if(a[i]=='B')cnt[i+1][1]++;
//     }

//     auto x = solve(1);
//     ll ans = 0;
//     for(int i = 1; i <= n; i++){
//         if(cnt[i][0]==cnt[i][1])ans++;
//     }

//     cout<<ans<<"\n";}

//     return 0;}

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

ll cnt[4007][2];
deq children[4007];
ll parent[4007];

pii solve(ll n){
    if(children[n].empty()){
        return {cnt[n][0],cnt[n][1]};
    }

    for(auto i : children[n]){
        pii ans = solve(i);
        cnt[n][0]+=ans.first;
        cnt[n][1]+=ans.second;
    }
    return make_pair(cnt[n][0],cnt[n][1]);
}

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        ll n;
        cin >> n;

        memset(cnt, 0, sizeof(cnt));
        memset(parent, 0, sizeof(parent));
        for(ll i = 0; i <= n; i++){
            children[i].clear();
        }

        for(ll i = 2; i <= n; i++){
            ll x;
            cin >> x;
            parent[i] = x;
            children[x].push_back(i);
        }

        string a;
        cin >> a;

        for(ll i = 0; i < a.length();i++){
            if(a[i]=='W'){
                cnt[i+1][0]++;
            }
            if(a[i]=='B'){
                cnt[i+1][1]++;
            }
        }
        auto z = solve(1);
        ll ans = 0;
        for(ll i = 1; i <= n; i ++){
            if(cnt[i][0]==cnt[i][1])ans++;
        }

        cout << ans << "\n";
    }

    return 0;}