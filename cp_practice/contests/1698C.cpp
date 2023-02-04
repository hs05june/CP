#include<bits/stdc++.h>
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

signed main(){
    CODE BY HARPREET
    int t; cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll,ll> m;
        for(ll i = 0 ; i < n ; i++){
            ll x; 
            cin >> x;
            m[x]++;
        }
        deque<ll> d;
        for(auto i : m){
            if(i.second>=3){
                for(int j = 0; j < 3 ; j++)d.push_back(i.first);
            }
            else{
                for(int j = 0; j < i.second ; j++)d.push_back(i.first);
            }
        }
        ll positive = 0,negative=0;
        bool zero = false;
        for(int i = 0 ; i < d.size();i++){
            if(d[i]==0)zero = true;
            else if(d[i]>0)positive++;
            else if(d[i]<0)negative++;
        }

        if(positive>=3 || negative>=3){
            cout << "NO\n";
            continue;
        }

        if((positive==2 && zero) || (negative==2 && zero)){
            cout << "NO\n";
            continue;
        }
        
        set<ll> s;
        bool ans = true;
        for(int i = 0; i < d.size();i++){
            s.insert(d[i]);
        }
        for(int i = 0; i < d.size();i++){
            for(int j = i+1; j < d.size();j++){
                for(int k = j+1; k < d.size();k++){
                    ll res = d[i] + d[j] + d[k];
                    if(!(s.count(res))){
                        ans = false;
                    }
                }
            }
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;}