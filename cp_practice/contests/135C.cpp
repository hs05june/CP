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

int num_of_digits(ll n){
    int ans = 0;
    while(n>0){
        ans++;
        n/=10;
    }

    return ans;
}

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        multiset<ll> s[2];
        for(int i=0; i<n; i++){
            ll x;
            cin >> x;
            s[0].insert(x);
        }
 
        for(int i = 0; i<n; i++){
            ll x;
            cin >> x;

            if(s[0].count(x)){
                s[0].erase(s[0].find(x));
            }
            else{
                s[1].insert(x);
            }
        }

        deque<int> xa[2];

        int cnt[2][11] = {0};

        for(auto i : s[0]){
            if(i<=10){cnt[0][i]++;}
            xa[0].push_back(i);
        }
        for(auto i : s[1]){
            if(i<=10)cnt[1][i]++;
            xa[1].push_back(i);
        }

        ll ans = 0;
        while(xa[0].size()>0 && xa[0].back()>9){
            ll x = xa[0].back();
            ll z = num_of_digits(x);
            xa[0].pop_back();
            cnt[0][z]++;
            ans++;
        }

        while(xa[1].size()>0 && xa[1].back()>9){
            ll x = xa[1].back();
            ll z = num_of_digits(x);
            xa[1].pop_back();
            cnt[1][z]++;
            ans++;
        }
        
            for(int j = 2; j < 10; j++){
                ans+=abs(cnt[0][j]-cnt[1][j]);
            }

        cout << ans << "\n";

    }

    return 0;}