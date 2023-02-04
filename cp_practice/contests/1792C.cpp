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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

int main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        string a;
        cin >> a;

        map<char,deq> m;

        for(char i = 'a'; i <= 'z'; i++){
            deq y;
            m.insert({i,y});
        } 

        for(int i  = 0; i < a.size(); i++){
            m[a[i]].push_back(i+1);
        }

        char start = a[0],end = a[a.size()-1];
        int ans = 0;
        deq ansdeq;
        char prev = start;
        if(start <= end){
            for(char x = start; x <= end; x++){
                ans += abs(x-prev);
                prev = x;
                for(auto i : m[x]){
                ansdeq.push_back(i);}
            }
        }
        else{
            for(char x = start; x >= end; x--){
                ans += abs(x-prev);
                prev = x;
                for(auto i : m[x]){
                ansdeq.push_back(i);}
            }
        }

        cout << ans << " " << ansdeq.size() << "\n";

        for(auto i : ansdeq)cout<<i << " ";
        cout << "\n";

    }

    return 0;}