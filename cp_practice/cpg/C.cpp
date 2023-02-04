#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

ull cnt[2][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        memset(cnt, 0, sizeof(cnt));

        string a,b;

        cin >> a >> b;

        int n = a.length();
        
        for(int i = 0; i < n; i++){
            cnt[0][a[i]-'0']++;
        }

        for(int i = 0; i < n; i++){
            cnt[1][b[i]-'0']++;
        }

        int t = 0;
        int x=0,y=0;

        t += min(cnt[0][0],cnt[1][1]);
        t += min(cnt[0][1],cnt[1][0]);

        for(int i = 0; i < t; i++){
            cout <<"1";
        }

        for(int i = 0; i < (n-t); i++){
            cout<<"0";
        }
        cout << "\n";
    }

    return 0;}