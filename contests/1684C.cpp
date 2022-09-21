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

        int n,m;
        cin >> n >> m ;

        ll a[n][m+1] = {0};
        ll maxi[n] = {0};
        bool check = true;
        deq row;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j] ;
                if(maxi[i] < a[i][j])maxi[i]=a[i][j];
                if(a[i][j]<a[i][j-1]){check = false;row.push_back(i);}
            }
        }

        if(check){
            cout << "1 1\n";
            continue;
        }

        deq column;
        int cnt = 0;
        bool ans = true;
        ll x = 0,y=0;

        for(int i = 1; i <= m; i++){
            if(a[row[0]][i] < a[row[0]][i-1]){
                // if(cnt==0){
                // column.push_back(i-1);
                // cnt++;}
                // else if(cnt == 1){
                // column.push_back(i);
                //     cnt ++;
                // }
                // else if(cnt >=2){
                //     ans = false;
                //     break;
                // }
                // column.push_back(i-1);
                if(a[row[0]][i-1]!=maxi[row[0]]){
                x = i-1;
                ++i;
                while(i<=m && a[row[0]][x]>=a[row[0]][i]){
                    ++i;
                }
                y = i - 1;}
                else{
                    x = i;
                    for(ll j = 1; j<=m; ++j){
                        if(a[row[0]][j]==maxi[row[0]]){
                            y = j;
                            break;
                        }
                    }
                }
            }
        }
        // cout << x << " " << y << endl;
        if(x>y)swap(x,y);

        // for(auto i : column){cout<<i<<" ";}

    //     if(column.size()==1 && a[row[0]][column[0]+1] < a[row[0]][column[0]]){
    //         column.push_back(column[0]+1);
    //     }

    //    if(column.size()!=2){ans = false;}
    // cout << x << " " << y << endl;

       if(ans){
            // ll x = column[0],y = column[1];

            for(int i = 0; i < n; i++ ){
                swap(a[i][x],a[i][y]);
            }

            for(int i = 0; i < n; i++){
                for(int j = 1; j <= m; j++){
                    if(a[i][j]<a[i][j-1]){
                        ans = false;
                        break;
                    }
                }
                if(!ans)break;
            }
       }

       ans ?  cout << x << " " << y << "\n" : cout<<"-1\n" ;

    }

    return 0;}