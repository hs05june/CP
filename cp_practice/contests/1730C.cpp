#include<bits/stdc++.h>
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
using namespace std;

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        string a;
        cin >> a;

        string b = "";

        char mini[a.length()+1];

        mini[a.length()] = '9';

        for(int i = a.length()-1; i >= 0; i--){
            mini[i] = min(mini[i+1],a[i]);
        }

        for(int i = 0; i < a.length(); i++){
            if(a[i]>mini[i]){
                if(a[i]=='9')b.push_back('9');
                else b.push_back(char(a[i]+1));
            }
            else{
                b.push_back(a[i]);
            }
        }

        sort(b.begin(), b.end());
        cout << b << "\n";
    }

    return 0;}