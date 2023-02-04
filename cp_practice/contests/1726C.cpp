#include<bits/stdc++.h>
#define ll long long
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
using namespace std;

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        ll n;
        cin >> n;

        string a;
        cin >> a;
        ll ans = 1;

        for(ll i = 0; i < a.length()-1; i++){
            if(a[i]=='(' && a[i+1]=='(')ans++;
        }

        cout << ans << endl;

    }

    return 0;}