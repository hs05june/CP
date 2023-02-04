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

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        string a[n],b[n];
        deque<pair<pii,pii>> ans;

        string x = "";

        for(int i = 0 ; i < m; i++){
            x.push_back('0');
        }

        for(int i = 0; i  < n; i++){
            cin >> a[i];
            b[i] = x;
        }

        if(a[0][0]=='1'){
            cout << "-1\n";
            continue;
        }

        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(a[i][j]=='1' && b[i][j]!='1'){
                    if(j!=0){
                        ans.push_back({{i+1,j},{i+1,j+1}});
                        b[i][j-1] = '0';
                        b[i][j] = '1';
                    }
                    else{
                        ans.push_back({{i,j+1},{i+1,j+1}});
                        b[i][j] = '1';
                        b[i-1][j] = '0';
                    }
                }
                else if(a[i][j]=='0' && b[i][j]!='0'){
                    ans.push_back({{i+1,j+1},{i+1,j+1}});
                    b[i][j] = '0';
                }
            }
        }

        cout << ans.size() << "\n";

        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
        }

    }

    return 0;}