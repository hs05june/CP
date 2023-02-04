#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);cout.tie(0);
#define HARPREET cout << fixed << setprecision(20);
int M = 1000000007;
using namespace std;

ll num_of_digits(ll num){
    ll ans = 0;

    while(num>0){
        ans++;
        num/=10;
    }

    return ans;
}

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        map<ll,ll> a,b;

        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            a[x]++;
        }
        
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            if(a[x]==0){
                b[x]++;
            }
            else if(a[x]>0){
                a[x]--;
            }
        }

        ll ans = 0;

        map<ll,ll> a1,b1;

        for(auto i : a){
            if(i.first<=9 && i.second > 0){
                a1[i.first]+=i.second;
            }
            else if(i.first > 9 && i.second>0){
                ll dig = num_of_digits(i.first);
                a1[dig]+=i.second;
                ans+=i.second;
            }
        }
        for(auto i : b){
            if(i.first > 0 && i.first<=9 && i.second > 0){
                b1[i.first]+=i.second;
            }
            else if(i.first > 9 && i.second>0){
                ll dig = num_of_digits(i.first);
                b1[dig]+=i.second;
                ans+=i.second;
            }
        }
  
        for(int i = 2; i<=9;i++){
            ans+=abs(a1[i]-b1[i]);
        }

        cout << ans << "\n";
    }

    return 0;}