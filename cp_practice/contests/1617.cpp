#include<bits/stdc++.h>
#define int long long
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

        int n;
        cin >> n;

        int arr[n+1] = {0};
        deq extras;

        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(x > n || arr[x]==1){
                extras.push_back(x);
            }
            else{
                arr[x] = 1;
            }
        }

        sort(extras.begin(), extras.end());

        bool ans = true;
        int z = extras.size()-1;

        for(int i = n; i>=1; i--){
            if(arr[i]==0){
                if(extras[z]-i > i){
                    z--;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }

        ans ? cout << extras.size() - z - 1 <<"\n": cout << "-1\n";

    }

    return 0;}