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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        string a,b;

        cin >> a >> b;

        map<char,ll> cnta,cntb;

        for(int i = 0; i < n; i++){
            cnta[a[i]]++;
            cntb[b[i]]++;
        }

        bool ans = true;

        for(char i = 'a';i <= 'c';i++){
            if(cnta[i]!=cntb[i]){
                ans = false;
                break;
            }
        }

        if(!ans){
            cout << "NO\n";
            continue;
        }

        int j = 0;

        for(int i = 0; i<n && j < n; i++){
            while(a[i]=='b')++i;
            while(b[j]=='b')++j;
            if(a[i]!=b[j] || (a[i]=='a' && i > j) || (a[i]=='c' && i < j)){
                ans = false;
                break;
            }
            else if(a[i]==b[j])++j;
        }

        ans ? cout << "YES\n" : cout << "NO\n";
        
    }

    return 0;}