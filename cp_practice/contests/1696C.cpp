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

int main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        ll n,m;
        cin >> n >> m;

        ll a[n];

        ll sum1 = 0,sum2 = 0;

        for(ll i = 0; i < n; i++){
            cin >> a[i];
            sum1+=a[i];
        }

        ll n1;
        cin >> n1;
        ll b[n1];
        for(ll i = 0; i < n1; i++){
            cin >> b[i];
            sum2+=b[i];
        }

        if(sum1!=sum2){
            cout << "NO\n";
            continue;
        }

        deque<pair<ll,ll>> first,second;
        // ll prev = 0;
        for(ll i = 0; i < n; i++){
            ll cnt = 1;
            while(a[i]%m==0){
                a[i]/=m;
                cnt*=m;
            }
                if(!first.empty() && a[i]==first[first.size()-1].first)first[first.size()-1].second += cnt;
                else{
                    first.push_back({a[i],cnt});
                }
            // for(int j = 1; j <= cnt; j++){
            //     first.push_back(a[i]);
            // }
        }
        for(ll i = 0; i < n1; i++){
            ll cnt = 1;
            while(b[i]%m==0){
                b[i]/=m;
                cnt*=m;
            }
            // for(int j = 1; j <= cnt; j++){
            //     second.push_back(b[i]);
            // }
                if(!second.empty() && b[i]==second[second.size()-1].first)second[second.size()-1].second += cnt;
                else{
                    second.push_back({b[i],cnt});
                }
        }

        bool check = true;

        // for(int i = 0; i< first.size();i++){
        //     cout << "{" << first[i].first << ","<<first[i].second<<"} ";
        // }

        // cout << "\n";
        // for(int i = 0; i< second.size();i++){
        //     cout << "{" << second[i].first << ","<<second[i].second<<"} ";
        // }

        if(first.size()!=second.size()){
            cout << "NO\n";
            continue;
        }

        for(ll i = 0; i < first.size(); i++){
            if(first[i].first!=second[i].first || first[i].second!=second[i].second){
                check = false;
                break;
            }
        }

        check ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;}