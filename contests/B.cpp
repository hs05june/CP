#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
        int n;
        map<int,pii> h;
        cin>>n;

        int x;

        for(int i = 1; i <= n; i++){
            cin >> x;
            if(h.count(x)){
                h[x].first = h[x].second;
                h[x].second = i;
            }
            else{
                h.insert({x,{0,i}});
            }
        }

        deque<int> maxi;
        
        for(auto z : h){
            if(z.second.first !=0){
                maxi.push_back(z.second.first);
            }
        }
        if(maxi.size() == 0)cout<<0<<"\n";
        else cout<<(*max_element(maxi.begin(),maxi.end()))<<"\n";
    }

    return 0;}