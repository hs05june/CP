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

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        string a;
        cin >> a;
        int prev[26] = {0};
        
        ll m = 0;

        for(int i = 0; i < a.length(); i++){
            if(prev[a[i]-'a']){
                m+=2;
                for(int i = 0; i < 26; i++)prev[i] = 0;
            }
            else prev[a[i]-'a'] = 1;
        }

        cout << a.length() - m << "\n";
    }

    return 0;}